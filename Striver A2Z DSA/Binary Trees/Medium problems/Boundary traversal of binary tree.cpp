/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when
you always travel preferring the left subtree over the right subtree.

Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.

Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the 
leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root 
from this as it was already included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 
*/

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void leftTree(Node* root, vector<int>& ans){
        if(!root) return;
        
        if(root->left){
            ans.push_back(root->data);
            leftTree(root->left, ans);
        }else if(root->right){
            ans.push_back(root->data);
            leftTree(root->right, ans);
        }
    }
    
    void leaf(Node* root, vector<int>& ans){
        if(!root) return;
        
        leaf(root->left, ans);
        leaf(root->right, ans);
        
        if(!root->left && !root->right) ans.push_back(root->data);
    }
    
    void rightTree(Node* root, vector<int>& ans){
        if(!root) return;
        
        if(root->right){
            rightTree(root->right, ans);
            ans.push_back(root->data);
        }else if(root->left){
            rightTree(root->left, ans);
            ans.push_back(root->data);
        }
    }
    
    vector <int> boundary(Node *root){
        vector<int> ans;
        if(!root) return ans;
        
        ans.push_back(root->data);
        
        if(root->left) leftTree(root->left, ans);
        if(root->left || root->right) leaf(root, ans);
        if(root->right) rightTree(root->right, ans);
        
        return ans;
    }
};
