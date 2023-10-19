/*
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
*/

//code 1:

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> 
        min_heap(nums.begin(), nums.begin() + k);
        
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        
        return min_heap.top();
    }
};

//code 2:

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> 
        min_heap(nums.begin(), nums.begin() + k);
        
        for (int i = k; i < nums.size(); i++) {
            min_heap.push(nums[i]);
            min_heap.pop();
        }
        return min_heap.top();
    }
};

//code 3:

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      
        priority_queue<int, vector<int>, greater<int>> pq;
      
        for(int x: nums){
            pq.push(x);
            if( pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};
