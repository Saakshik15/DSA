/*
Problem Statememt:

Given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
Return the sum of all subarray ranges of nums.
  
A subarray is a contiguous non-empty sequence of elements within an array.
*/

/*
approach 1: brute force approach- two loops

first, we will find out all the subarrays of the array and then find out the difference between the 
largest and smallest element in the subarrray and return the sum of all ranges.

Algorithm
Set answer = 0.
Iterate over every left index of subarrays left.
With every fixed left, initialize minVal = maxVal = nums[left], iterate over every right index right of subarrays.
For each right index right, update minVal and maxVal by nums[right]. Then update answer += maxVal - minVal.
*/

//code :

long long subArrayRanges(vector<int>& nums) {
    int n = int(nums.size());
    long long answer = 0;
    
    for (int left = 0; left < n; ++left) {
        int minVal = nums[left], maxVal = nums[left];
        for (int right = left; right < n; ++right) {
            maxVal = max(maxVal, nums[right]);
            minVal = min(minVal, nums[right]);
            answer += maxVal - minVal;
        }
    }
    
    return answer;
}

//time complexity : O(N^2)
//space complexity : O(1)

/*
Approach 2: monotonic stack

to find the total sum of the subarray ranges, we can individually find out max for all subarrays and sum them up,
then find out the min for all subarrays and sum them up and them find out the difference in order to find the sum of ranges.




*/
