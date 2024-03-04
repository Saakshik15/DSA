/*
If the components are connected, then we dont need to make a separate call, 
the dfs function will mark the visited nodes as 1 which are connected.
However, if the components are not connected, we need to make separate calls for each node checking where vis[node] = false.
So, whenever we will make a call like that, we will add it to the number of provinces.
  */

//by using the adj matrix itself

class Solution {
public:

    void traverse(vector<vector<int>>& isConnected, int n, vector<int>& vis, int i){
        vis[i]=1;

        for(int j=0; j<n; j++){
            if(isConnected[i][j] && vis[j]==0)
                traverse(isConnected,n,vis,j);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<int> vis(n,0);
        int provinces=0;

        for(int i=0; i<n; i++){
            if(vis[i]==0){
                provinces+= 1;
                traverse(isConnected,n,vis,i);
            }
        }
        return provinces;
    }
};

//by converting the adj matrix to adj list and then finding provinces:

class Solution {

private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (auto& adjNode : adj[node]) {
            if (!visited[adjNode])
                dfs(adjNode, adj, visited);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // create adjacency list
        vector<vector<int>> adj(n, vector<int>());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] == 1)
                    adj[i].emplace_back(j);
            }
        }

     //finding provinces
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int node = 0; node < n; node++) {
            if (!visited[node]) {
                provinces++;
                dfs(node, adj, visited);
            }
        }

        return provinces;
    }
};
