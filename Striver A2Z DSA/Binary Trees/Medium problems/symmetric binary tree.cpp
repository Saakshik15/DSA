/*
Excluding the root, if we observe, the left subtree and right subtree of the root would be mirror images of each other.

that is, we we traverse the left subtree in the order: Root, left, right 
and if we traverse the right subtree in the order:     root, right, left

then if we get the same answer at each node, we will find out if the tree is symmetric or not.
*/

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
    bool helper(TreeNode* left, TreeNode* right){
        if(!left || !right) return left==right;

        if(left->val == right->val) 
            return (helper(left->left, right->right) && helper(left->right, right->left));
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }
};
