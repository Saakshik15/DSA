/*
We can represent graph in two ways, 
one is adjacency matrix and the other way is adjacency list.
*/

/*
Adjacency matrix:

In this way, we use a matrix to represent the graph having n vertices and m edges.
We initialize the matrix having n x n size with 0s to avoid garbage values,
then in next m lines we take edges as input and mark those edges as 1 in the matrix.
*/

//code for representation:

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

	// Initialize adjacency matrix with zeros
    int adj[n + 1][n + 1] = {0}; 

    // Store the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        adj[u][v] = 1;
        adj[v][u] = 1; //Only if graph is undirected, not required for directed
    }

    // Print adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

//space complexity : O(n^2)



/*
The space required to store the adjacency matrix is too much.
Thus, we can use something like adjacency list to store the graph instead of matrix.

Given n vertices, now we will maintain a list for each vertex, which will store to which nodes the current vertex is connecting to.

eg, if we have 5 nodes and 6 edges as:
1 2
1 3
3 4
2 4
2 5
4 5

then we can create adjacency list as:

Nodes:
0: {}
1: {2,3}
2: {1,4,5}
3: {1,4}
4: {3,2,5}
5: {2,4}
*/

//code for representation:

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1); // Initialize adjacency list

    // Store the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
      
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Only if graph is undirected, not required for directed
    }

    // Print adjacency list
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

//space complexity: O(2E) for undirected
//space complexity: O(E) for directed


/*
Now, if the graph is given to be weighted, in the matrix, instead of marking fields as 1, 
we will mark down the weight of the edge in the matrix.

In case of adj lists, we will be storing the edges along with weights in pairs to get the weights of the edges.
*/









