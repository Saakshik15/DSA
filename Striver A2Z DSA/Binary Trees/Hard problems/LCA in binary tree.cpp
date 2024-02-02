/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q 
as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/

/*
Approach brute:

We can find the solution using brute force by finding path from root to node first for both the given nodes
we will store tha path in two data structures for both the nodes
Then, compare ds of these two and find out the last node which are common, 
eg, if for node 4, path is: [1 2 3 4]
and for node 7, it is: [1 2 6 7]
then the LCA for both the nodes will be 2, which is last common node in both.

Now, the time and space complexity using these two methods is comparatively more, O(n0 ofr traversing both and O(n) for storing paths.


Approach optimized:

Now, to optimize the time and space complexity, traverse the tree first
Then from root if we traverse the the left first & then right, return the node if the node is found on the path and 
if not found return null.
If at a node, a non-null value from one of left & right is returned, take the non-null value ignoring null from one side.
Now, if at a particular node if from both the left and right traversals, if nodes are returned, then we can conclude that we have got 
the common ancestor, which will be the node where both the left and right traversals return a value rather than a
single null or both null and return the current node on which we have got two values.
Then we will keep returning the value of the node where we have got both the nodes till root thus resulting in ans.
*/

//code:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;

        TreeNode* left= lowestCommonAncestor(root->left, p, q);
        TreeNode* right= lowestCommonAncestor(root->right, p, q);

        if(!left) return right;
        else if(!right) return left;
        else return root; 
    }
};
