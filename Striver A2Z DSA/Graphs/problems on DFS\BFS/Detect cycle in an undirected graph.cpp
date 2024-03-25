
//Using BFS


bool detect(int src, vector<int> adj[], int vis[]){
        //mark the source node as visited first
        vis[src]=1;
        
        queue<pair<int, int>> q;
        
        //push source in queue with -1, since it has no parent node
        q.push({src, -1});
        
        while(!q.empty()){
            //storing the node as well as the parent it came from in the queue
            int node= q.front().first;
            int parent= q.front().second;
            q.pop();
            
            for(auto adjNode: adj[node]){
                //if node is not visited push the node along with its parent in the queue
                if(!vis[adjNode]){
                    vis[adjNode]= 1;
                    //push the node along with parent, which is the current node
                    q.push({adjNode, node});
                }
                //if above condition is false, that means node is visited
                //but node can be only visited if it is already a parent node if not cycle
                //otherwise if it's not a parent node that means node is visited by some other node, as in cycle
                else if(parent != adjNode){
                    return true;
                }
            }
        }
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]= {0};
        
        //since the graph may have connected components as well, we will 
        //iterate over the visited array to check for all components
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detect(i, adj, vis)) return true;
            }
        }
        return false;
    }




//using DFS


bool dfs(int node, int parent, vector<int> adj[], int vis[]){
        vis[node]=1;
        
        //iterating over the neighbours of the node in adj list
        for(auto adjNode: adj[node]){
            //if node not visited, visit the node
            if(!vis[adjNode]){
                //if any of the call return true for a cycle, return true for all calls
                if(dfs(adjNode, node, adj, vis)) return true;
            }
            //if adj node is not parent which the node came fron, then it has been already visited by some other node
            //in that case, there is a cycle, so return true
            else if(adjNode!= parent) return true;
        }
        //in any of the above cases if cycle is not found, then graph does not have a cycle return false
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};
        
        //iterating over the visited array in case if the graph has connected components
        for(int i=0; i<V; i++){
            if(!vis[i]) {
                if(dfs(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }



//
