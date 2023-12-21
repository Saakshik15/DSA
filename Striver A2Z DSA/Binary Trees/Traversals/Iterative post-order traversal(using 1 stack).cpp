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

//code 1: (coding ninjas)

vector<int> postorderTraversal(TreeNode* root){

    stack<TreeNode*> stk;
    vector<int> ans;

    stk.push(root);

    while (!stk.empty()){
        TreeNode* cur = nodeStack.top();
        nodeStack.pop();
        ans.push_back(cur->data);

        if(cur->left != NULL) nodeStack.push(cur->left);
        if(cur->right != NULL) nodeStack.push(cur->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


//code 2: (leetcode)

vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()){
            TreeNode* cur = stk.top();
            stk.pop();
            ans.push_back(cur->val);

            if(cur->left != NULL) stk.push(cur->left);
            if(cur->right != NULL) stk.push(cur->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
