/*
Lower Bound : The smallest Index at which arr[ind] >= target

The lower bound algorithm finds the first or the smallest index in a sorted array 
where the value at that index is greater than or equal to a given key i.e. x.

The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found,
the lower bound algorithm returns n i.e. size of the given array.
*/

/*
The first approach to find the lower bound is a brute force approach, in which we search the 
index such that arr[ind] >= target 
*/

//Code for brute force approach :

int lowerBound(vector<int> arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] >= x) {
            return i;
        }
    }
    return n;
}

/*
Optimal approach to find the lower bound is to perform a binary search on the array 
*/

//Pseudo-code :

function(arr, target, n){
  low =0, high=n-1;
  ans=n;

  while(low<=high){
    mid = (low+high)/2;

    if(arr[mid]>=n){
      ans=mid;
      high=mid-1;
    }
    else
      low=mid+1;
  }
}

//Code :
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}





