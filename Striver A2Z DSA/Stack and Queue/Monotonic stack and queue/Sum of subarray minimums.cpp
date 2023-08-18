/*
Problem statement :
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444
*/

/*
Approach 1 : brute force approach 

The brute force approach to this problem is to find out all the subarrays of the given array, and then finding minimum of all the 
subarrays and summing them up.
This will end up taking O(N^3) time complexity and O(1) space complexity.

We can further optimize this approach and find out the minimum while finding the subarrays itself, which can be done in O(N^2) time.
*/

//code :

int minSubsetSum(vector<int>& arr) {
    int n = arr.size();
    int totalSum = 0;

    // Generate all subsets and calculate the sum of minimum elements
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int minElement = arr[i];
            for (int k = i; k <= j; ++k) {
                minElement = std::min(minElement, arr[k]);
            }
            totalSum += minElement;
        }
    }
    return totalSum;
}





