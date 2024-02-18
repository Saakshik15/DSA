vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        
        int vis[V] ={0};  //to keep track of visited nodes
        vis[0]=1;
        
        queue<int> q;
        q.push(0);   //ps has 0 based indexing
        
        while(!q.empty()){
            int node= q.front();
            q.pop();
            
            bfs.push_back(node);
            
            for(auto it: adj[node]){  //for each node, iterate over its adj list which is array
                if(!vis[it]){
                    q.push(it);
                    vis[it]=true;
                }
            }
        }
        return bfs;
    }



//
