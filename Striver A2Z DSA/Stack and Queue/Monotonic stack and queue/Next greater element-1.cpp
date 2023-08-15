/*
Problem statement and explaination of answer:

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0<=i < nums1.length, find the index j such that nums1[i]==nums2[j] & determine the next greater element of nums2[j] in nums2. 
If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

In other words, given arr1 is a subset of arr2. So, we have to find the next greater element of all the elements present in the arr1 
according to the order of elements in the arr2.
explaination of 1st eg :
we are given arr1 and arr2, thus we have to find the next greater element of all the elements of arr1.
the first element in arr1 is 4, according to the arr2, there is no next element which is greater than 4 in arr2, so -1.
the next element in arr1 is 1, according to the order of elements in the arr2, next greater element of 1 is 3.
the next element in arr1 is 2, according to arr2, 2 is the last element, so there is no next greater element so -1.
finally, the output will be [-1, 2, -1] which are the next greater elements of [4, 1, 2] respectively.
*/

/*

Solution 1 : brute force approach

in the first approach, we will be traversing the arr1 and find out the next greater element of all the elements present in the arr1 
by traversing through the elements of arr2.
thus we will be returning the resultant array which has stored all the next greater elements of the elements in arr1.
*/

/*
Approach 2 : using monotonic stack.

In this appraoch, we will simply traverse the given arr2 from the end of the array and will use a stack to find next greater elements.

initializing a stack and traversing elements of the array, :
if the stack is empty, push current element onto the stack
if top of stack is greater than current value, assign top as next greater element of the current value and push current value on stack.
if top of stack is less than current value, pop elements from stack until there is an element greater than the current element on top.
if we pop all the elements but still did not find any element greater than current, then assign the next greater element as -1.
(Note: using this technique, the stack will by default be storing the elements in increasing order from top to bottom.)

then, we will return the next greater elements of the elements present in arr1.
*/

//code :

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    stack<int>st;
    unordered_map<int,int>mp;
    int n=nums2.size();
    int m=nums1.size();

    st.push(nums2[n-1]);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && st.top()<=nums2[i]){
            st.pop();
        }
        if(!st.empty()){ 
            if(i<n)
            mp[nums2[i]]=st.top();
        }
        st.push(nums2[i]);
    }
    vector<int>ans(m,-1);

    for(int i=0;i<m;i++){
        if(mp[nums1[i]]!=0){
            ans[i]=mp[nums1[i]];
        }
    }
    return ans;
}

//time complexity : O(2n + m) where n is size of arr2 and m is size of the subset arr, arr1.
//space complexity : O(m) for storing the NGE's of arr1 elements.
