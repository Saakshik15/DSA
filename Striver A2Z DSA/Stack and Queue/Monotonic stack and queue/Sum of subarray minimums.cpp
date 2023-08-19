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

The brute force approach to this problem is to find out all the  contiguous subarrays of the given array, 
and then finding minimum of all the subarrays and summing them up.
This will end up taking O(N^2) time complexity and O(1) space complexity.
*/

//code :

 int mod= 1e9 +7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;

    // Generate all subsets and calculate the sum of minimum elements
        for (int i = 0; i < n; i++) {
            int minElement = arr[i];
            for (int j = i; j < n; j++) {
                    minElement = min(minElement, arr[k]);
                totalSum += minElement;
                totalSum %= mod; 
            }
        }
        return totalSum;
    }

//time complexity : O(N^2) gives TLE
//space complexity : O(1)


/*
Approach 2 : optimal approach 

In this approach, we will find total number of subarrays in which a particular value is minimum.

for example, array is [1, 6, 4, 3] 
Now, suppose, the total number of subarrays in which the number 1 will be minimum is 'a'
simililary, 'b' for 6, 'c' for 4, and 'd' for 3.
now, the toal sum of all the minimum elements of the subarrays for the given array will be 
sum = (1*a + 6*b + 4*c + 3*d) 
where the a,b,c,d variables are the total number of subarrays in which 1, 6, 4, 3 will be the minimum element.
*/




