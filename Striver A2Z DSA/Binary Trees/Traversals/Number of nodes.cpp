/*
Problem:

Given an integer N, determine the maximum number of nodes present on 'Nth' level in a binary tree.

eg. When N=3;
for level 1: 1 node
for level 2: 2 nodes
for level 3: 4 nodes
*/

int numberOfNodes(int n){
    return pow(2,n-1);
}
