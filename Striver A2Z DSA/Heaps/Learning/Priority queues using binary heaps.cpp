int pop(vector<int> &heap){
    if(heap.empty()) return -1;
    
    // Topmost element of the heap is the largest
    int ans = heap[0];

    // Move the last element to the root
    heap[0] = heap.back();
    heap.pop_back();

    // Restore the heap property
    int i = 0;
    int n = heap.size();
    while (true) {
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
        int largest = i;

        if (leftIndex < n && heap[leftIndex] > heap[largest]) {
            largest = leftIndex;
        }
        if (rightIndex < n && heap[rightIndex] > heap[largest]) {
            largest = rightIndex;
        }
      
        if (largest != i) {
            swap(heap[i], heap[largest]);
            i = largest;
        } else {
            break;
        }
    }
    return ans;
}


// Code Snippet of the push function: 

void push(vector<int> &heap, int x) {
      heap.push_back(x);

       // Posistion of the current inserted element.
       int pos=heap.size()-1;

       // Shifting the element up until it reaches the top most node if it is larger than its parent.
       while(pos>0){
           int parent = (pos-1)/2;
           if(heap[pos] > heap[parent]) {
               swap(heap[parent],heap[pos]);
               pos=parent;
          }
         else{
             // As parent is larger the element now is in its correct position. 
             break;
         }
     }
 }
