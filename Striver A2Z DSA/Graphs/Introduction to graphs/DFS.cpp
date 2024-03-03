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
