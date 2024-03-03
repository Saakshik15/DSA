// In DFS, we explore neighbours of neighbours recursively

// Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, vector<int> adj[], int vis[], vector<int>& ans){
        vis[node]=1;
        ans.push_back(node);
        
        //traverse all the neighbours of current node
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, ans);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        int vis[V]={0};
        dfs(0, adj, vis, ans);
        return ans;
    }


/*
In dfs, we explore all the neighbours of current node first:

eg. if adj list is:

0: {1,2}
1: {2}
2: {0}

then, for exploring 0 we will explorewhole adj list of 0 fist, like:
1: explore all neighbours of 1 and further neighbours of those and after exploring back, come back to where we left off, in adj list of 0, then,
2: exploring all neighbours of 2 and come back from where we left off and so on.

IN DFS, we explore neighbours of neighbours recursively
*/


// PS 2:
/*
Problem statement
Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges, 
the information about edges is given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. 
print its DFS traversal.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
E is the number of edges present in graph G.

Note : The Graph may not be connected i.e there may exist multiple components in a graph.
*/

void dfs(int node, vector<int> adj[], vector<int>& ans, int vis[]){
    vis[node]=1;
    ans.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, ans, vis);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges){
    //creating adj list
    vector<int> adj[V];
    for(int i=0; i<edges.size(); i++){
        int u= edges[i][0];
        int v= edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int vis[V]= {0};
    vector<vector<int>> res;

    //loop through the vertices and look for unvisited vertices and go in depth
    for(int i=0; i<V; i++){
        if(!vis[i]){
            vector<int> ans;
            //traversing non visited node
            dfs(i, adj, ans, vis);
            //pushing the ans to the result vector
            res.push_back(ans);
        }
    }
    return res;
}
