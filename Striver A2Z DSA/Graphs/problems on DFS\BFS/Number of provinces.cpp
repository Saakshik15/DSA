/*
If the components are connected, then we dont need to make a separate call, 
the dfs function will mark the visited nodes as 1 which are connected.
However, if the components are not connected, we need to make separate calls for each node checking where vis[node] = false.
So, whenever we will make a call like that, we will add it to the number of provinces.
  */

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
