/*
Ceil of a value is the closest number just greater than or equal to the given value.

Eg, if given values are 1,3,6,8,9 and key=5 then ceil = 6

Finding a ceil in BST means finding a number just greater than or equal to the given value.
*/

//code:

int findCeil(BinaryTreeNode<int> *root, int x){
    int ceil=-1;

    while(root){
        if(root->data==x) return x;

      //we dont need a value smaller than the key, we need greater value, so check in right
        if(root->data < x){
            root=root->right;
        }else{
            ceil= root->data;
            root= root->left;
        }
    }
    return ceil;
}

