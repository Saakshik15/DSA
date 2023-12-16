/*
Binary tree will be represented in the form of nodes (as in linked list)
A particular node will have three fields, 
  1. Data of the current node 
  2. Pointer to the left child
  3. Pointer to the right child
*/
// The code for which can be given as:

//structure for Node
struct Node{
  int data;
  struct Node* left;
  struct Node* right;

  Node(int val){
    data = val;
    left = right = NULL;
  }
};

int main(){
  struct Node* root = new Node(1);

  root->left = new Node(2);
  root->right = new Node(3);

  root->left->right = new Node(5);
}

