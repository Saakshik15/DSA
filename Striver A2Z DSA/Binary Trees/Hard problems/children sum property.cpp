/*
Problem statement:

children sum property of a binary tree means value of each node should be equal to the sum of the children of the nodes.
that is, a node's value should be the sum of its left child's value + right child's value
If the property is not maintaned, we can increment value of any node
*/

/*
Approach:

while traversing the tree, while going downwards in the recursive tree, change the value of nodes below and 
while traversing up again by returning from the function call, add left and right nodes to the parent node.
*/

//code:

void changeTree(Node* root){
  if(!root) return;
  int child=0;

  if(root->left) child+= root->left->data;
  if(root->right) child+= root->right->data;

  if(child >= root->data) 
    root->data= child;
  else {
    if(root->left) root->left->data= root->data;
    else if(root->right) root->right->data= root->data;
  }
  changeTree(root->left);
  changeTree(root->right);

  int total=0;
  if(root->left) total+= root->left->data;
  if(root->right) total+= root->right->data;
  if(root->left || root->right) root->data= total;
}

//code 2:

int fun(BinaryTreeNode<int>* root, int par){
    if(!root) return 0;
  
    int l=fun(root->left,max(root->data,par));
    int r=fun(root->right,max(root->data,par));
    root->data=max(l+r,max(root->data,par));
   	return root->data;
}

void changeTree(BinaryTreeNode <int> * root) {
    fun(root,0);
}

/*
Variation 2:
dont change the tree, just check if the tree follows child sum proprty as stated above.

Problem statement
Return true if all non-leaf nodes in a given binary tree have a value that is equal to the sum of their child nodes, 
otherwise return false.
*/

//code:

bool isParentSum(Node *root){
    if(!root || (!root->left && !root->right)) return true;

    int sum=0;
    if(root->left) sum+= root->left->data;
    if(root->right) sum+= root->right->data;
    if(sum==root->data) return isParentSum(root->left) && isParentSum(root->right);
    return false;
}

