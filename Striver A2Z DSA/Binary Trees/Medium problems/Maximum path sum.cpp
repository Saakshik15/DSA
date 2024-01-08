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

    int maxSum(TreeNode* node, int& sum){
        if(node==NULL) return 0;

        //for leftSum and rightSum, max is used in cases where a negative sum is returned.
        int leftSum = max(0, maxSum(node->left, sum));
        int rightSum= max(0, maxSum(node->right, sum));

        sum = max(sum, leftSum+ rightSum+ node->val);

        return node->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        maxSum(root, sum);
        return sum;
    }
};
