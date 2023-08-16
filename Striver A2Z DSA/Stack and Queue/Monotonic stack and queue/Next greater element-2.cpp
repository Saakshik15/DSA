/*
Problem statement:

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, 
which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

example:
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
*/

/*
Approach 1 : brute force appraoch
we will be traversing the array using two for loops in the brute force approach and find the 
next greater element for each element in the array
*/

/*
Approach 2:

we will use a stack, traverse the array fro the end to the begining and will find out the next greater lement for each elent present
in the array.

initializing a stack and traversing elements of the array, from end of the array:
if the stack is empty, push current element onto the stack
if top of stack is greater than current value, assign top as next greater element of the current value and push current value on stack.
if top of stack is less than current value, pop elements from stack until there is an element greater than the current element on top.
if we pop all the elements but still did not find any element greater than current, then assign the next greater element as -1.
(Note: using this technique, the stack will by default be storing the elements in increasing order from top to bottom.)

since we are given a circular array, we will be traversing the same array twice by using the 
modulo operator to access the indexes of the elements of the array since the array is circular.

for traversing the array twice, we will use : for(int i=((2*n)-1); i>=0; i--)
and for accessing the indexes we will be accessing them by using : arr[n%i]
*/

//code :

vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> stk;
    int n= nums.size();
    vector<int> nge(n,-1);

    for(int i=((2*n)-1); i>=0; i--){
        while(!stk.empty() &&nums[i%n]>=stk.top()){
            stk.pop();
        }
        if(i<n){
            if(!stk.empty())
                nge[i]=stk.top();
        }
        stk.push(nums[i%n]);
    }
    return nge;
}

//time complexity: O(2N) since we are traversing the array almost twice
//space complexity : O(N) where n is the size required for the stack.
