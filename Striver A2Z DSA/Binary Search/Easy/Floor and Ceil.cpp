/*
Floor : The floor of x is the largest element in the array which is smaller than or equal to x.
  largest element in the array <= x
Ceil : The ceiling of x is the smallest element in the array greater than or equal to x.
  smallest element in the array >= x

The implementation of ceil is similar to implementing the lower bound algorithm using binary search.
But, for finding the floor, we have to implement it using the binary search algorithm as :

If arr[mid] <= x: arr[mid] is a possible answer. 
  So, we will store it and will try to find a larger number that satisfies the same condition. 
  That is why we will remove the left half and try to find the number in the right half.
If arr[mid] > x: The arr[mid] is definitely not the answer and we need a smaller number. 
  So, we will reduce the search space to the left half by removing the right half.
*/

//code to implement floor and ceil :

int findFloor(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] <= x) {
			ans = arr[mid];
			//look for smaller index on the left
			low = mid + 1;
		}
		else {
			high = mid - 1; // look on the right
		}
	}
	return ans;
}

int findCeil(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] >= x) {
			ans = arr[mid];
			//look for smaller index on the left
			high = mid - 1;
		}
		else {
			low = mid + 1; // look on the right
		}
	}
	return ans;
}




  
  
