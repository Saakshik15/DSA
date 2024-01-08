/*
Diameter of a binary tree is the longest distance between two nodes.
Also, this path does not need to pass through the root.

Logically we can observe that the diameter or the longest path of a tree can actually be:
  the maximum left height + right height
*/

//Naive approach:

findMax(root){
  if( root == NULL) return;

  lh= findLeftHeight(root->left);
  lh= findRightHeight(root->right);

  maxi = max(maxi, lh+rh);

  findMax(root->left);
  findMax(root->right);
}

//TC: O(N^2)

//optimized approach:

class Solution {
public:

    int height(TreeNode* node, int& d){
        if(node == NULL) return 0;

        int lh= height(node->left, d);
        int rh= height(node->right, d);

        d= max(d, lh+rh);

        return 1+ max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        height(root,d);
        return d;
    }
};


// TC: O(N)

