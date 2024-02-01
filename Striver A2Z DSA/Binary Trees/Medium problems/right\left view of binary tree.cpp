/*
for the right view of the binary tree, we can say that for each level, the node at the end of the level will 
be considered in the right side view of the binary tree.
But if we traverse the tree level-order from right to left, then the first node will be the node which is 
to be considered in the right side view of the binary tree.

Similarly, for the left side view of binary tree, traversing the tree from left to right level-order, the
first node will be considered in the left side view of binary tree.

Now, if the tree is full binary tree(where all nodes are filled) then the time complexity to traverse it using 
level-order traversal would be O(n) and space will be equal to the number of nodes at the last level, which is maximum.

So, we will traverse the tree depth wise to minimize space complexity, which in this case would be O(h) -height of the tree.
But, if the tree is skewed tree (i.e., all nodes have only one child) then the height of tree will be comparatively maximum.

Regardless, we will use the method of depth wise traversal to find out the left/right side view of the binary tree
because the solution code is concise and crisp for the depth wise traversal.
*/

/*
Approach: (for right side view)

We will prefer the reverse pre-order traversal to find out the right side view of the binary tree.
so, the traversal will be: Node, Right, Left

we will be traversing the tree using recursive reverse pre-order traversal and keep a data structure for storing nodes.
We will also have a variable level for keeping track of the level number while traversing.

While we are traversing a tree, if the current node has left or right child, we will increase the level by one,
simultaneously, we will calculate size of data structure on which we are storing the right view of the tree.
Whenever our level increases, if the number of level is equal to the size of data structure we have, it means that it
is the first time we are traversing that level and we will add the node to the data structure.
(eg, initially ds has size 0 and root has level 0, so root will be added to ds as level==ds size)

This way, we will be traversing the tree while getting the right side view of the binary tree.
*/

//code for right side view 

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

    void revPreOrder(TreeNode* root, int level, vector<int>& ans){
        if(!root) return;

        if(level== ans.size()) ans.push_back(root->val);
        if(root->right) revPreOrder(root->right, level+1, ans);
        if(root->left) revPreOrder(root->left, level+1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        revPreOrder(root, 0, ans);
        return ans;
    }
};


//code for left side view

#include<bits/stdc++.h>

void preOrder(BinaryTreeNode<int>* root, int level, vector<int>& ans){
    if(!root) return;

    if(level==ans.size()) ans.push_back(root->data);
    if(root->left) preOrder(root->left, level+1, ans);
    if(root->right) preOrder(root->right, level+1, ans);
}

vector<int> printLeftView(BinaryTreeNode<int>* root) {
    vector<int> ans;
    preOrder(root, 0, ans);
    return ans;
}


