/*
Problem statement:
Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Example 1:
Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6
*/

/*
Solution: 

Approach: Sliding window

Create a deque to keep the necessary elements only, eg, as we slide the window if we encouter any element greater than what currently
is present in the deque, then we will remove that element from it as it is not useful (since there is a greater element in the current
window than that). Also, the elements after the current max even though smaller than current max shall be kept as when we remove the 
current max and when it won't be there in the next window, the next element might be the max element for the next window.

For each window, the answer will be always the front element of deque

sliding the window: while sliding the window, if front of deque is the first element of window, we will remove it
else we will just simply slide the window

*/

//code :

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        vector<int> ans;
        int l=0, r=0;

        while(r < nums.size()){

          //if current element is greater than elements in the queue, pop all elements so that only useful elements will be in deque
            while(!deq.empty() && nums[r] > deq.back())
                deq.pop_back();
            deq.push_back(nums[r]);

          //if window size is obtained
            if(r-l+1 == k){
              //if window size is obtained get answer
                ans.push_back(deq.front());

              //if l is part of the deque, remove it so that we can slide the window
                if(nums[l] == deq.front())
                    deq.pop_front();
                l++;
            }
          //writing r++ outside the conditions make sure r is always incremented regardless we obtain the window size or not
            r++;
        }
        return ans;
    }

//time complexity : O(N)
//space complexity : O(K)
