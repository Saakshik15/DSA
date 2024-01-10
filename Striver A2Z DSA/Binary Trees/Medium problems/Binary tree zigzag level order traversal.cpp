/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).
*/

/*
We will use a queue in order to keep track of what node we are traversing.
push the root to the queue first.
We will keep track of whether we are traversing from left to right or right to left by flag variable (0 or 1)
for 0 direction is: left to right and 
for 1 the direction in right to left.

we will store the ans in vector<vector<int>>, in the inside vectors we will store the traversal of each level.
*/

//code:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;  //for storing final result
        if(!root) return res;

        queue<TreeNode*> q;  //queue for traversal
        q.push(root);
        bool flag= true; //true-> left to right

        while(!q.empty()){
            int size = q.size();
            vector<int>level(size);   //vector of size of queue for storing each level traversal

            for(int i=0; i<size; i++){
                TreeNode* node= q.front();  //taking front element of the queue
                q.pop();

                //if flag is left to right (true) insert as the order is 
                //if flag is right to left(false) insert in reverse order
                int idx= (flag)? i: (size-1-i);   
                level[idx] = node->val;

                //pushing the child nodes of the current node in te queue
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            flag= !flag;            //inverting the flag for the next level traversal
            res.push_back(level);   //pushing the current level on the result vector
        }
        return res;
    }
};
