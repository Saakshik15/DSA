/*
Problem statement:
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,
    G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.
*/

/*
approach 1: brute froce approach

the brute force approach is to take a nested loop, and for every element keep iterating back till we find a smaller element.
This can be O(N^2) in worst case.
*/

//pseudo-code for brute froce approach :

for i = 0 to size(arr):
    ans[i] = -1
    for j = i - 1 to 0:
        if arr[j] < arr[i]:
            ans[i] = arr[j]
            break

/*
Approach 2:
All elements with index smaller than i - 1 and greater than A[i-1] are useless to 
us because they would never qualify for G[i], G[i+1], ...
Using the above fact, we know that we only need previous numbers in descending order.

The algorithm would look something like :
1) Create a new empty stack st
2) Iterate over array `A`,
   where `i` goes from `0` to `size(A) - 1`.
    a) We are looking for value just smaller than `A[i]`. So keep popping from `st` till elements in `st.top() >= A[i]` or st becomes empty.
    b) If `st` is non empty, then the top element is our previous element. Else the previous element does not exist. 
    c) push `A[i]` onto st
*/

//code :

vector<int> Solution::prevSmaller(vector<int> &arr) {
    vector<int> vec;
    stack<int> stk;
    
    int n= arr.size();
    vec.push_back(-1);
    stk.push(arr[0]);
    
    for(int i=1; i<n; i++){
        while(stk.size()!=0 && stk.top()>=arr[i]) 
            stk.pop();
        if(stk.size()==0)
            vec.push_back(-1);
        else
            vec.push_back(stk.top());
        stk.push(arr[i]);
    }
    return vec;
}

//time complexity : O(N)
//space complexity : O(N)

