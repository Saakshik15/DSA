//check if two trees are same

//code 1:

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        if (p->val == q->val) return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        return false;
    }
};

//code 2 (same approach: one liner) :

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return (!p || !q) ? (p==q) : ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

