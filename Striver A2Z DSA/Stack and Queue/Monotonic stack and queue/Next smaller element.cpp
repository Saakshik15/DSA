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

//pseudo/code for brute froce approach :

for i = 0 to size(arr):
    ans[i] = -1
    for j = i - 1 to 0:
        if arr[j] < arr[i]:
            ans[i] = arr[j]
            break

/*
Approach 2:




*/
