/*
Problem statement:

Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes 
visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position 
then consider the left ones only(i.e. leftmost). 
For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.
*/

/*
Approach:

similar to the problem of vertical order traversal in which we drew imaginary lines vertically on the teee to identify the 
vertical levels, we would draw lines to find out the top view.

We will assign 0 value to the level of the root and line-1 for left levels and line+1 for the right side levels.

If we draw vertical lines, we can observe that, for each vertical level the first node we visit using level order traversal (bfs)
is the same node which we have to consider for the top view of the tree.

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

  if the line number does NOT exist in the map:
    add it to the map along with the data of the node
    
  if current node has left node, add it to queue with line-1
  if current node has right node, add it to queue with line+1
  (repeat till queue is empty)

lastly, traverse the entire map and add the values to the ans vector
(since the map is ordered we will have nodes from left to right)
*/

//code:

vector<int> topView(Node *root){
        vector<int> ans;
        if(root==NULL) return ans;
        
        map<int, int> mpp;
        queue<pair<Node*, int>> que;
        
        que.push({root, 0});
        
        while(!que.empty()){
            auto curr= que.front();
            que.pop();
            
            Node* node= curr.first;
            int line= curr.second;
            
            if(mpp.find(line) == mpp.end()) mpp[line]= node->data;
            
            if(node->left) que.push({node->left, line-1});
            if(node->right) que.push({node->right, line+1});
        }
        
        for(auto it: mpp) ans.push_back(it.second);
        
        return ans;
    }
