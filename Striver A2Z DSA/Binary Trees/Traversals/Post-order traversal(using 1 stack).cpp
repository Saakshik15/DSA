//code 

// Binary Tree Node structure
    class TreeNode{
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

//iterative post-order traversal using 1 stack
vector<int> postorderTraversal(TreeNode* root){

    stack<TreeNode*> nodeStack;
    vector<int> ans;

    nodeStack.push(root);

    while (nodeStack.size() > 0){
        TreeNode* cur = nodeStack.top();
        nodeStack.pop();
        ans.push_back(cur->data);

        if(cur->left != NULL) nodeStack.push(cur->left);
        if(cur->right != NULL) nodeStack.push(cur->right);
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}


