/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).
*/

/*
We will use a queue in order to keep track of what node we are traversing.
push the root to the queue first.
We will keep track of whether we are traversing from left to right or right to left by flag variable (0 or 1)
for 0 direction is: left to right and 
for 1 the direction in right to left.

we will store the ans in vector<vector<int>>, in the inside vectors we will store the traversal of each level.
*/

//code:

