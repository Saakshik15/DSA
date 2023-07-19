/*
Problem Statement: Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.

Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
*/

/*
Solution : 

approach 1 (brute force)
if an element appears twice in a sequence, either the previous or next element will be same. 
But only for the single element, this condition will not be satisfied. So, to check this the condition will be the following:
If arr[i] != arr[i-1] and arr[i] != arr[i+1]: If this condition is true for any element, arr[i], we can conclude this is the single element.

edge cases :
If n == 1: This means the array size is 1. If the array contains only one element, we will return that element only.
If i == 0: This means this is the very first element of the array. The only condition, we need to check is: arr[i] != arr[i+1].
If i == n-1: This means this is the last element of the array. The only condition, we need to check is: arr[i] != arr[i-1].
*/

//code for brute force approach:

int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size();
    if(n==1) return arr[0];

    for(int i=0; i<n; i++){
        if(i==0){
            if(arr[i] != arr[i+1]) return arr[i];
        }
        else if(i== n-1){
            if(arr[i] != arr[i-1]) return arr[i];
        }
        else{
            if(arr[i] != arr[i+1] && arr[i] != arr[i-1]) return arr[i];
        }
    }
    return -1;
}
//time complexity : O(N)
//space complexity : O(1)



/*
Approach 2:

The optimal approach is based on the following observations :
1.when we are on the left half side of the single element, the pairs are (even index, odd index).
  element is on the right side in this case.
2.when we are on the right half side of the single element, the pairs are (odd index, even index).
  element is on the right side in this case.

also, to identify the single element, neither of the right element and the left element will be equal to the single element.
*/

//code :

function(arr, n){

  if(n==1) return arr[0];
  if(arr[0] != arr[1]) return arr[0];
  if(arr[n-1] != arr[n-2]) return arr[n-1];

  int low =1, high = n-2;

  while(low<=high){

    int mid = (low+high)/2;
    if (arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]) return arr[mid];
    
    //on the left half
    if((mid%2 == 1 && arr[mid-1] == arr[mid]) || (mid%2 == 0 && arr[mid+1] == arr[mid]))
      low = mid+1;
    else //on the right half
      high = mid-1;
  }
  return -1;
}

//time complexity : O(logN)
//space complexity : O(1)















