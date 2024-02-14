/*
Traverse the tree and add the given node at the leaf nodes checking left or right using greater or less than conditions.
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp= root;
        TreeNode* node= new TreeNode(val);

        if(!root) return node;

        while(root){
            if(root->val<val){
                if(root->right==NULL) {
                    root->right=node;
                    break;
                }
                else root= root->right;
            }else{
                if(root->left==NULL){
                    root->left=node;
                    break;
                } 
                else root= root->left;
            }
        }
        return temp;
    }
};
