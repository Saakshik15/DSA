/*
A peak element is an element that is strictly greater than its neighbors.

Given an array, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
*/


/*
Solution:

Approach 1 : Linear traversal of the array 

In this approach, we will linearly traverse the array and check if the left and right elements are smaller than the current element.
This way, we will return the element which is both greater than the element to the left of it and to the right of it as well.
*/

//code :

int findPeakElement(vector<int>& arr) {
        int n= arr.size();
        for(int i=0; i<n; i++){
            if(((i==0) || (arr[i-1] < arr[i])) && ((i==n-1) || (arr[i] > arr[i+1]))) return i;
        }
        return -1;
    }

//Time complexity : O(N)
//Space coplexity : O(1)


/*
Approach 2: Optimal approach

This approach uses binary search algorithms to eliminate the halves.
This is based on the following observations :
1. The left half of the peak element has an increasing order. This means for every index i, arr[i-1] < arr[i].
2. The right half of the peak element has a decreasing order. This means for every index i, arr[i+1] < arr[i].

Now, we can identify the left and right halves, by checking current index, i, like the following:
1. If the current index is peak element :
    If arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1] is true then mid is the peak element and return mid.
2. If arr[i] > arr[i-1] : we are in the left half.
    If we are in the left half of the peak element, we have to eliminate this left half    
    low = mid+1, because peak element is on the right side.
3. If arr[i] > arr[i+1] : we are in the right half.
    If we are in the right half of the peak element, we have to eliminate this right half     
    high = mid-1, because peak element is on the left side.
*/


//code :

int findPeakElement(vector<int>& arr) {

  int n= arr.size();
  if (n==1) return 0;
  if(arr[0] > arr[1]) return 0;
  if(arr[n-1] > arr[n-2]) return n-1;
  
  int low=1, high=n-2;
  //since we have already checked for the first and last elements we will shrink the seach space
  
  while(low<=high){
      int mid = (low+high)/2;
  
      //if the element is the peak element
      if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
          
      //peak is on the right or the element is lying on the increasing curve
      else if(arr[mid] > arr[mid-1]) low = mid+1;
  
      //peak is on the left or the element is lying on the decreasing curve
      else high = mid-1;
  }
  return -1;
}

//time complexity : O(logN)
//space complexity : O(1)




  



