/*
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
*/

//using min heap

/*
In min heap we will always be storing k elements.
We will then traverse the array and add first k elements to the min heap.
Then, for the next element, when min heap is full with k elements, then for inserting the next element:
if the next element is greater than top of the min heap we will pop the top element and insert the next element.
If the next element is smaller than the top then the element is not a candidate of largest elements so we will not push it on min heap.
*/

//code :

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> 
        min_heap(nums.begin(), nums.begin() + k);
        
        for (auto i: nums) {
            if (i > min_heap.top()) {
                min_heap.pop();
                min_heap.push(i);
            }
        }
        return min_heap.top();
    }
};

/*
Other approach where instead of having a min heap with size k, if size of min heap exceeds k
we will pop the top elements till the size of min heap is k.
So, the top elements which are smaller will be removed from the min heap and 
as there are exactly k elements in the min heap, then the top element will be the kth largest element of the array.
*/

//code 2:

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      
        priority_queue<int, vector<int>, greater<int>> pq;
      
        for(int x: nums){
            pq.push(x);
            if( pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};


