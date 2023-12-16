/*
Problem:

Given an array 'arr' that contains 7 integers representing the values of nodes in a binary tree. 
This represents level order. The first element of the array represents the value of the root node.
Your objective is to construct a binary tree using the remaining 6 elements of the array, 
creating nodes for each of these values and return root node.
*/

//code:


// Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};


Node* createBinaryTree(vector<int>& arr, int start){

    // Base case
    if(start >= arr.size()) return NULL;

    // Create a new node with the current data
    Node *root = new Node(arr[start]);
    root->left = createBinaryTree(arr, 2 * start + 1);
    root->right = createBinaryTree(arr, 2 * start + 2);

    return root;
}

Node* createTree(vector<int>&arr){
    return createBinaryTree(arr, 0);
}



