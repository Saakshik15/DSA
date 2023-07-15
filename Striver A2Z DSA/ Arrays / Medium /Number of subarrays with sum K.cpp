/*
Problem Statement: Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

*/

/*

Solution :

Approach 1 : Brute force 

The brute force solution of this problem will be to generate all subarrays and find sum K.
*/

//pseudo-code :

count =0;
sum=0;

for(i=0; i<n; i++){
  for(j=0; j<n; j++){
    sum=0;
    for(k-i; k<=j; k++){     
      sum = sum + arr[k];
    }
  }
  if(sum==k)
    count++;
}

// TIme complexity : O(N*N*N) as we are using three for loops
//Space complexity : O(1) as we are not using any extra space


/*
Approach 2 : better approach

In this approach instead of running a third for loop for the sum we will calculate the sum in the second loop itself.
*/

//pseudo-code :

count =0;
for(i=0; i<n; i++){
  sum=0;
  for(j=0; j<n; j++){
    sum = sum + arr[j];
  }
  if(sum==k)
    count++;
}

//Time complexity : O(N*N)
//Space complexity : O(1)

/*
Approach 3 : Optimal approach
Prefix sum

declaring a map to store the prefix sums and their counts.
setting the value of 0 as 1 on the map.
running a loop(say i) from index 0 to n-1(n = size of the array).
For each index i, we will do the following:

  adding the current element i.e. arr[i] to the prefix sum.
  calculating the prefix sum i.e. x-k, for which we need the occurrence.
  adding the occurrence of the prefix sum x-k i.e. mpp[x-k] to our answer.
  storing the current prefix sum in the map increasing its occurrence by 1.
*/

//code :

int subarraySum(vector<int>& nums, int k) {
  unordered_map<int,int> mp;
  int preSum=0,ans=0;
  mp[0] = 1;

  for(auto it:nums){
      preSum += it;
      int remove = preSum - k;
      if(mp.find(remove) != mp.end()){
          ans += mp[remove];
      }
      mp[preSum]++;
  }
  return ans;
}

//Tme complexity : O(N)
//Space complexity : O(N) in worst case




