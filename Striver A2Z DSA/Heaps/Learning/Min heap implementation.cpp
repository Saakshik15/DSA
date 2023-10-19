class minHeap {
public:

    vector<int> heap;
    int size, capacity;

    // Constructor for the class.
    minHeap(int cap) {
        heap.resize(cap);
        size=0;
        capacity = cap;
    }

    void heapify(int i){
        int smallest =i;

        int leftIndex = 2*i+1;
        int rightIndex = 2*i+2;

        if(leftIndex < size && heap[leftIndex] < heap[smallest]){
            smallest=leftIndex;
        }
        if(rightIndex < size && heap[rightIndex] < heap[smallest]){
            smallest = rightIndex;
        }
        
        if(i != smallest){
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }
    

    // Implement the function to remove minimum element.
    int extractMinElement() {
        if(size==0) return -1;

        int ans = heap[0];
        swap(heap[0], heap[size-1]);
        size--;

        heapify(0);

        return ans;
    }

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        if(ind >= size) return;
        swap(heap[ind], heap[size-1]);
        size--;

        heapify(ind);
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        if(size==capacity) return;

        heap[size] = val;
        size++;

        int index = size-1;

        while(index>=0){
            int parent = (index-1)/2;

            if(heap[parent] > heap[index]){
                swap(heap[parent], heap[index]);

                index= parent;
            }else break;
        }
    }
};
