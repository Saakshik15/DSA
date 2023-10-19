/*
Poblem statement :
given an array of size 'N' which is an array representation of min heap.
You need to convert this in heap array representation to a max-heap array representation.
Return the max-heap array representation.

eg. given the following min heap:
[1,2,3,6,7,8]
It can be converted to the following max heap:
[8,7,3,6,2,1]

*/

//code:

void maxHeap(vector<int> &arr, int data, int n) {
  
	arr.push_back(data);
	int size= arr.size();
	int index= size-1;

	while(index>0){
		int parent = (index-1)/2;
		if(arr[index] > arr[parent]){
			swap(arr[index], arr[parent]);
			index= parent;
		} else {
			return ;
		}
	}
}

vector<int>MinToMaxHeap(int n, vector<int>&arr) {
	vector<int> ans;
	for(int i=0; i<n; i++){
		maxHeap(ans, arr[i], n);
	}
	return ans;

}
