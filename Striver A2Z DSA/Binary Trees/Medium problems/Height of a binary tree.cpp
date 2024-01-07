/*
The height of the tree if we are at the root node can be stated as:

1 (for the current node) + max(left subtree, right subtree)

*/


//code: (recursive approach)

int heightOfBinaryTree(TreeNode<int> *root)
{
	if(!root) return 0;

    int lh= heightOfBinaryTree(root->left);
    int rh= heightOfBinaryTree(root->right);

    return 1+ max(lh,rh);
}
