//Post-order traversal: left right root

//code:

// Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };


//postOrder traversal

void postOrder(TreeNode *root, vector<int>& ans){
    if (root==NULL) return;

    postOrder(root->left, ans);
    postOrder(root->right, ans);
    ans.push_back(root->data);
}

vector<int> postorderTraversal(TreeNode *root){
    vector<int> ans;
    postOrder(root, ans);
    return ans;
}




