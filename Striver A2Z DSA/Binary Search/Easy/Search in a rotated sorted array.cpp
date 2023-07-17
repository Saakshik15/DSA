/*
Problem Statement :
Given a sorted arraylist arr consisting of n elements.
Now, the array is rotated at some unknown pivot

eg. consider a sorted array: {1, 2, 3, 4, 5}. If we rotate this array at index 3, it will become: {4, 5, 1, 2, 3}.

now, we have to find the index at which a given element is present.
*/

/*
Brute force approach : 
performing a linear search on the array and returning the index of the element if it is present
if the element is not present, return -1.

time complexity for this will be O(N)
*/

//code for brute force approach :
int search(vector<int>& arr, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == k)
            return i;
    }
    return -1;
}


/*
optimal approach :
in the optimal approach, we will perform a binary search on the array.

for every index, one of the 2 halves will always be sorted
First, we will identify the sorted half :

1.If arr[low] <= arr[mid]: This condition ensures that the left part is sorted.
  a) If arr[low] <= target && target <= arr[mid]: 
  It signifies that the target is in this sorted half. So, we will eliminate the right half (high = mid-1).
  b) Otherwise, the target does not exist in the sorted half. So, we will eliminate this left half by doing low = mid+1.
  
2. Otherwise, if the right half is sorted:
  a) If arr[mid] <= target && target <= arr[high]: 
  It signifies that the target is in this sorted right half. So, we will eliminate the left half (low = mid+1).
  b) Otherwise, the target does not exist in this sorted half. So, we will eliminate this right half by doing high = mid-1.

This process will continue until low<=high, 
  if the search space is exhausted, we will return -1.
*/

//code :

int search(vector<int>& arr, int target) {
        
        int low=0, high=arr.size()-1;

        while(low <= high){

            int mid=(low+high)/2;

            if(arr[mid]==target) return mid;

            //check if left is sorted
            if(arr[low] <= arr[mid]) {

                if(arr[low] <= target && target <= arr[mid]){
                    high = mid-1;
                }
                else{
                low = mid+1;
                }
            }

            //check if right is sorted
            else{

                if (arr[mid]<= target && target <= arr[high]){
                    low = mid+1;
                }
                else{
                    high=mid-1;
                }
            }

        }
        return -1;
    }

//time complexity : O(logN)
//space complexity :O(1)

