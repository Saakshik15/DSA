/*
Problem statement:
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/

/*
Solution :

Initialize maxLen to 0, l to 0, and r to 0. maxLen will store the maximum length of a subarray,
l is the left pointer of the sliding window, and r is the right pointer.

Iterate through the binary array using a sliding window approach :
If nums[r] is 0, decrement the value of k by 1, as it is allowed to flip this 0 to 1.
Check if k becomes less than 0. If so, it means more than k zeros in the current window have been flipped. 
In this case, move the left pointer l to the right until k becomes non-negative. 
While moving l, if nums[l] is 0, increment k back by 1 to account for the flip.
Increment the right pointer r to expand the window and continue repeating until whole array is iterated.
Finally, return r - l, which represents the length of the longest subarray of 1s that can be achieved by flipping at most k zeros.

*/

//code :

int longestOnes(vector<int>& nums, int k) {
        int maxLen =0, l=0, r=0;
        int n= nums.size();

        while(r<n){
            if(nums[r]==0){
                k--;
            }
            if(k<0){
                if(nums[l]==0)
                    k++;
                l++;
            }
            r++;
        }
        return r-l;
    }

//time complexity :O(N)
//space complexity: O(1)

