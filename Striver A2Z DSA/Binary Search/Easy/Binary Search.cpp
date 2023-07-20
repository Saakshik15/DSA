/*
Binary search is only applicable in a sorted search space. The sorted search space does not necessarily have to be a sorted array.
It can be anything but the search space must be sorted.
In binary search, we generally divide the search space into two equal halves and then try to locate which half contains the target. 
According to that, we shrink the search space size.

Eg. the given array is = {3, 4, 6, 7, 9, 12, 16, 17} and target = 6.
*/


/*
Iterative Implementation :

We will use two pointers in this approach, high and low.
Initially, the low should point to the first index and high to the last index of the search space.
Then, we will divide the search space into two halves (the search space is sorted in this case) so, we will take a mid pointer in this case
where, mid = (low+high) / 2
There are three cases after dividing the search space :
1. arr[mid] = target element
  in this case, we have found the target element and will return the index
2. arr[mid] > target element
  In this case, the target element is lesser than mid element, so it is more likely to be found in the first half of the array
  So, in this case we will shrink the array by moving the high pointer to (mid-1) th index
3. arr[mid] < target element
  In this case, the target element is greater than mid element, so it is more likely to be found in the second half of the array
  So, in this case we will shrink the array by moving the low pointer to (mid+1) th index

We continue these steps until either we found the target or the search space becomes invalid i.e. high < low.
*/

//Code for Iterative Implementation :

int search(vector<int>& nums, int target) {

        int lb=0, ub=nums.size()-1,mid;
        
        while(lb<=ub){

            mid=(lb+ub)/2;
            if(target==nums[mid])
                return mid;
            else if(target>nums[mid])
                lb=mid+1;
            else
                ub=mid-1;

        }
        return -1;
    }


/*
Recursive Approach :

In this approach, we will recursively perform binary search in the array until we find the target element.
The steps involved are as follows:

1. Set a low pointer at the begining of the array, a high pointer at the end of the array, and 
divide the search space into two halves by mid= (high+low)/2
  
2. Compare the mid element with the target:
There are three cases :
i.   If arr[mid] == target: We have found the target. From this step, we can return the index of the target possibly.
ii.  If target > arr[mid]: This case signifies our target is located on the right half of the array. 
     So, the next search space will be the right half.
iii. If target < arr[mid]: This case signifies our target is located on the left half of the array. 
     So, the next search space will be the left half.

3. Based on the probable location of the target we will trim down the search space.
If the target occurs on the left, we should set the high pointer to mid-1. Thus the left half will be the next search space.
Similarly, if the target occurs on the right, we should set the low pointer to mid+1. Thus the right half will be the next search space. 
*/

//Code for recursive approach :

int binarySearch(vector<int>& nums, int low, int high, int target) {

    if (low > high) return -1; //Base case.

    int mid = (low + high) / 2;
    if (nums[mid] == target) return mid;
    else if (target > nums[mid])
        return binarySearch(nums, mid + 1, high, target);
    else
        return binarySearch(nums, low, mid - 1, target);
}


  
