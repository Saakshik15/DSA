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

//Iterative post order traversal using two stacks
vector<int> postorderTraversal(TreeNode* curr){

    vector<int> postOrder;
    if (curr == NULL) return postOrder;

    stack <TreeNode*> s1;
    stack <TreeNode*> s2;
    s1.push(curr);

    while (!s1.empty()) {
        curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr -> left != NULL) s1.push(curr -> left);
        if (curr -> right != NULL) s1.push(curr -> right);
    }
    while (!s2.empty()) {
    postOrder.push_back(s2.top() -> data);
    s2.pop();
    }
    return postOrder;
}

