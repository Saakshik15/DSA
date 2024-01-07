/*
An empty tree is a height-balanced tree. A non-empty binary tree is a height-balanced binary tree if

1. The left subtree of a binary tree is already the height-balanced tree.
2. The right subtree of a binary tree is also the height-balanced tree.
3. The difference between heights of left subtree and right subtree must not more than ‘1’.
*/

//naive approach :

bool check(node){
  if(!node) return true;

  lh= findLeftHeight(node->left);
  rh= findRightHeight(node->right);

  if(abs(rh-lh)>1) return false;

  bool left= check(node->left);
  bool right= check(node->right);

  if(!left || !right) return false;
  return true;
}
//TC: O(N^2)

//optimized approach



