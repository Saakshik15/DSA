/*
When we delete a node from a Binary Search Tree(BST), the BST properties should remain the same.
Hence, we have 3 cases for deleting a node from a BST :

1.The node is a leaf node - In this cases, we can just delete the node and return the root, since deleting any elaf node doesn't affect the remainig tree.
2. The node has one child - In this case, replace the node with the child node and return the root.
3. The node has 2/more children - In this case, in order to conserve the BST properties, we need to replace the node with it's inorder successor (The next node that comes in the inorder traversal) i.e; we need to replace it with either :
1. The greatest value node in it's left subtree (or)
2. The smallest value node in it's right subtree
and return the root.

Time Complexity : O(h) - h = height of the tree.
(Worst case Time Complexity : O(n) )
*/

//code:


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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root) 
            //traverse till node is found
            if(key < root->val) root->left = deleteNode(root->left, key);
            else if(key > root->val) root->right = deleteNode(root->right, key);       
            
            else{
                if(!root->left && !root->right) return NULL; //No child 
                if (!root->left || !root->right) //one child: replaace node with its child
                    return root->left ? root->left : root->right;    //One child contion -> replace the node with it's child
                
                //Two/more child condition: inorder successor replace  
                TreeNode* temp = root->left;                        
                while(temp->right != NULL) temp = temp->right;        
                root->val = temp->val;        

                //finally deleting the node
                root->left = deleteNode(root->left, temp->val);        
            
                /*
                (or) for two/more children condition
                TreeNode *temp = root->right;
                while(temp->left != NULL) temp = temp->left;
                root->val = temp->val;
                root->right = deleteNode(root->right, temp);		
                */
            }
        
        return root;
    }   
};
