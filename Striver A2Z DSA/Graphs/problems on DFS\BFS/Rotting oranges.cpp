/*
Problem: rotting oranges

Intuition
BFS Overview:
BFS explores nodes level-by-level from a starting node.
It uses a queue to maintain the order of node exploration.
Nodes are visited in the order of their distance from the starting node.

BFS for Rotting Oranges:
In this problem, BFS helps us find the minimum time for all oranges to rot.
We treat each orange as a node and its neighboring oranges as adjacent nodes.
Starting from initially rotten oranges, BFS simulates the rotting process level by level.
Each level of BFS represents a unit of time.
By the end of BFS, if there are any unrotten oranges left, they couldn't be reached by the rotting process, so we return -1.

Intuition Behind BFS:
Think of being in a maze and exploring all paths level-by-level until you find the exit.
BFS explores neighbors first before moving to the next level.
It ensures the shortest path is found in unweighted graphs, which aligns with our goal of finding the shortest time for oranges to rot.

Approach
Use Breadth-First Search (BFS).
Initialize variables for grid dimensions, time, and counts of fresh oranges, then utilize a queue to perform BFS traversal.
During traversal, neighboring oranges are explored, simulating the rotting process by infecting adjacent fresh oranges.
Time increments with each level of traversal.
If any fresh oranges remain unrotten after traversal, indicating they couldn't be reached by the rotting process, the function returns -1. Otherwise, it returns the time taken for all oranges to rot.

Complexity
Time complexity:
O(n∗m)

Space complexity:
O(n∗m) ...worst case for queue
*/


//code:

class Solution {
public:

    //function to check if indices are valid or not
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1){
            return true;
        }
        return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int time=0, fresh=0;

        //make a queue of pairs for the indexes and for breadth first search traversal
        queue<pair<int,int>> q;

        //loop over the grid first
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2) {
                    //if orange is rotten, then push the orange indices in the queue
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    //keep count of fresh oranges to check at the end if all are rotten
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;

        //BFS traversal
        while(!q.empty()){
            int size= q.size(); 
            int temp=0; 
            //temp is for keeping a check on whether any neighbouring orange 
            //is rotten or not by that orange

            //loop to traverse the queue
            for(int i=0; i<size; i++){ 
                pair<int,int> p= q.front(); 
                q.pop(); 

                int x1= p.first;  
                int y1= p.second;  

                int ax[4]= {1, -1, 0, 0};
                int ay[4]= {0, 0, 1, -1};

                //looping over to check if we can rot any oranges using the popped pair from queue
                for(int i=0; i<4; i++){
                    int x= ax[i]+ x1; 
                    int y= ay[i]+ y1; 

                    //if we can rot an orange, 
                    if(isValid(x,y, n, m, grid)){
                        temp++;         // !=0 means at least an orange is rotten
                        fresh--;        //decrease cout of fresh
                        grid[x][y]=2;   //change the orange to rotten
                        q.push({x,y});  //push the rotten orange to queue for its own traversal
                    }
                }
            }
            if(temp!=0) time++;  //if any one orange is rotten, that means increment the time
        }
        return (fresh==0)? time: -1;  
        //if there are no fresh oranges return time 
        //else -1 since not all oranges are rotten and fresh are still left
    }
};



//

