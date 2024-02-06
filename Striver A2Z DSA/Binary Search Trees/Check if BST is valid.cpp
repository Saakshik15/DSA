/*
Problem statement
You are given an array ‘order’ which represents the inorder traversal of a binary search tree.
Find out if this traversal is valid or not.
Note: All values in the BST must be unique.
*/

/*
Intuition: 
The inorder traversal of BST is a sorted array, moreever, the condition that all values must be unique is given.
*/

//code:

bool isValidBST(vector<int> &order){
    for(int i=0; i<order.size()-1; i++){
        if(order[i]>=order[i+1]) return false;
    }
    return true;
}
