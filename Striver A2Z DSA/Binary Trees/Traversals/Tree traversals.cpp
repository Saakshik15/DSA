// DFS traversal types:
// In-order traversal:   Left Root Right
// Pre-order traversal:  Root Left Right
// Post-order traversal: Left Right Root

// BFS traversal: 
// Traverse the tree according the the breadth of the tree
// also known as level order traversal because the traversal is done level by level

/*
Problem:

You have been given a binary tree of N nodes, where the nodes have integer values.
Your task is th return the in-order, pre-order and post-order travrsals of the given binary tree.
*/



//code:

//Binary tree node structure:

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

//In-order traversal
void inOrder(TreeNode* root, vector<int>& ans) {
    if (root==nullptr) return;

    inOrder(root->left,ans);
    ans.push_back(root->data);
    inOrder(root->right,ans);
}

//Pre-order traversal
void preOrder(TreeNode* root, vector<int>& ans) {
    if (root==nullptr) return;

    ans.push_back(root->data);
    preOrder(root->left,ans);
    preOrder(root->right,ans);
}

//Post-order traversal
void postOrder(TreeNode* root, vector<int>& ans) {
    if (root==nullptr) return;

    postOrder(root->left,ans);
    postOrder(root->right,ans);
    ans.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans(3);

    inOrder(root, ans[0]);
    preOrder(root, ans[1]);
    postOrder(root, ans[2]);
    return ans;
}


