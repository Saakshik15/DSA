/*
Problem statement:

Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. 
For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.
*/

/*
Approach:

(approach is similar to the top view of binary tree.)

We will assign 0 value to the level of the root and line-1 for left levels and line+1 for the right side levels.

If we draw vertical lines, we can observe that, for each vertical level the last node we visit using level order traversal (bfs)
is the same node which we have to consider for the bottom view of the tree.

So, for the main approach, 
we will first create a map(not unordered since we have to print nodes from leftmost to rightmost nodes)
the first value of the map will store the line number which will be mapped to the value of the data.
To traverse, we will create a queue of pairs of Node and the line number.

Algorithm:
first, create a map of int, int for storing line, nodes value
second, create a queue of pair<node, int> for storing <node traversed, line number>
create a vector of ans for returning.

If root is null return the empty ans vector.

push root value to the queue

while the queue is not empty:
  store the front value (pair) of the queue and pop it from queue.

    add the line number to the map along with the data of the node 
    (unlike top view, it doesn't matter if it already exist or not, since the last nodes will always be traversed at last in bfs)
    
  if current node has left node, add it to queue with line-1
  if current node has right node, add it to queue with line+1
  (repeat till queue is empty)

lastly, traverse the entire map and add the values to the ans vector
(since the map is ordered we will have nodes from left to right)
*/

//code:

vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        
        q.push({root,0});
        
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            
            Node* temp= it.first;
            int line= it.second;
            
            mp[line]= temp->data;
            
            if(temp->left) q.push({temp->left, line-1});
            if(temp->right) q.push({temp->right, line+1});
        }
        for(auto it:mp) ans.push_back(it.second);
        return ans;
    }
