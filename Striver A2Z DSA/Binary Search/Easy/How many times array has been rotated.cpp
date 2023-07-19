/*
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values).
Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated. 

Observation :
We can easily observe that the number of rotations in an array is equal to the index(0-based index) of its minimum element.
So, in order to solve this problem, we have to find the index of the minimum element.
*/


//code : (similar to find minimum in rotated sorted array)

int findKRotation(vector<int> &arr){
    
  int low = 0, high = arr.size() - 1;
  int mini = INT_MAX, index=0;

  while (low <= high) {
      int mid = (low + high) / 2;

      //if left part is sorted:
      if (arr[low] <= arr[mid]) {
          // keep the minimum:
          if(arr[low] < mini){
            mini = arr[low];
            index= low;
          }
          // Eliminate left half:
          low = mid + 1;
      }
      else { //if right part is sorted:
          // keep the minimum:
          if(arr[mid] < mini) {
            mini= arr[mid];
            index= mid;
          }
          // Eliminate right half:
          high = mid - 1;
      }
  }
  return index;
}

//time complexity : O(logN)
//space complexity : O(1)



