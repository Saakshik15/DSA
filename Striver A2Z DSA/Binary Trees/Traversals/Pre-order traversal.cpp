// Pre-order traversal: root left right

// code:

//TreeNode class structure
template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

//Pre-order traversal code:
void preOrder(TreeNode<int>* root, vector<int>& ans) {
    if (root==NULL) return;

    ans.push_back(root->data);
    preOrder(root->left,ans);
    preOrder(root->right,ans);
}

vector<int> preOrder(TreeNode<int> * root){
    vector<int> ans;
    preOrder(root, ans);
    return ans;
}





