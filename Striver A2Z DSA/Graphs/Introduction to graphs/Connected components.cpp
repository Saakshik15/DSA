/*
If a graph has several nodes and doesn't have edges between some nodes, the graph is in some components,
which can be said that the whole graph is not connected via edges.

So, in this type of graph we cannot visit every node since the graph is in components and not totally connected.

To avoid this and to visit each and every node, we use a visited array to keep track of what nodes have been 
visited and what nodes haven't been visited.
*/

//to add visited edges,

vis[10]; //maintaining an array of visited nodes

for(i=1 to 10){
  if(!vis[i]) traverse(i); //if not visited, traverse and mark visited in traverse itself
}


//problem:

/*
Problem statement:

Problem statement
You are given ‘n’ cities, some of which are connected by bidirectional roads. You are also given an ‘n x n’ matrix 
i.e. ‘roads’, where if city ‘i’ and ‘j’ are connected by a road then ‘roads[i][j]'= 1, otherwise ‘roads[i][j]' = 0.

A province is a group of cities that are either directly or indirectly connected to each other through roads.
The goal is to count and return the total number of such provinces in the given matrix.

Example:
n = 4, roads = [ [1, 1, 1, 0],
                 [1, 1, 1, 0],
                 [1, 1, 1, 0],
                 [0, 0, 0, 1] ]
                 
So, there are ‘2’ provinces.

Sample input 2:
4
1 1 0 0 
1 1 0 0 
0 0 1 1 
0 0 1 1 
Sample output 2:
2
Explanation of sample input 2:
n = 4, roads = [ [1, 1, 0, 0],
                 [1, 1, 0, 0],
                 [0, 0, 1, 1],
                 [0, 0, 1, 1] ]
So, there are ‘2’ provinces.

Note:
1. A city is connected to itself. So, for every city ‘i’, ‘roads[i][i] = 1’.

Constraints:
1 <= 'n' <= 200
roads[i][j] is 1 or 0.
roads[i][j] == roads[j][i]
*/


//code:

void traverse(vector<vector<int>>& roads, int n, vector<bool>& vis, int i){
    vis[i]=1;

    for(int j=0; j<n; j++){
        if(roads[i][j] && vis[j]==0)
            traverse(roads,n,vis,j);
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    vector<bool> vis(n);
    int comp=0;

    for(int i=0; i<n; i++){
        if(vis[i]==0){
            comp+= 1;
            traverse(roads,n,vis,i);
        }
    }
    return comp;
}
