/*
Problem statement :
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.
*/

/*
Approach 1 : brute force approach

In this approach, we will find out the maximum possible area by considering each block individually.
  eg, the block is [7, 1, 5, 6, 2, 3, 1]
Now, if we consider the 2 at index number 4, then, we can make a rectange out of it like this:
to the left, we can take upto 5 because height of 1 is not greater than or equal to 2 to make a rectangle.
to the right, we can take upto 3, because here too, height of 1 is less than 2 which cannot for a rectangle.
thus, now we have a rectangle of 2 X (1 + 2 + 1) = 2 X 4 =8.
1+2+1 means, 1 for height of 2 itself + 2 on the left and + 1 on the right.

  thus, it can be observed that in order to make a rectangle and find out the area for each rectangle, 
we can only take blocks before the NEXT SMALLER ELEMENT both on th right and left sides.

but, this brute force way of finding the maximum area will end up taking almost O(N^2) time complexity.
*/

/*
Approach 2 :  finding NSE and PSE using monotonic stack & storing them in arrays 

In this approach, for every element, we will first compute the NSE and PSE and store them in an array which can be used as 
precomputed values while finding the max area.

but, this approach will have 
time complexity : O(N) average tc
space complexity : O(3N) for 2 arrays and stack
which is consuming extra space. 
*/

