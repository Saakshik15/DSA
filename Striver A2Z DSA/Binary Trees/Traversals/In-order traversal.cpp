// In-order traversal: left root right

//code:

// Binary Tree Node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

// In-order traversal
void inOrder(TreeNode* root, vector<int>& ans){
    if (root==NULL) return;

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    inOrder(root, ans);
    return ans;
}




