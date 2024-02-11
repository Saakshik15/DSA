//code 1: 

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root->data == x) return true;
    
    if(root->data > x && root->left) return searchInBST(root->left,x);
    if(root->data < x && root->right) return searchInBST(root->right, x);

    return false;
}

//code 2:

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(root->val == val) return root;

        if(root->val > val) return searchBST(root->left, val);
        if(root->val < val) return searchBST(root->right, val);

        return NULL;
    }
};
