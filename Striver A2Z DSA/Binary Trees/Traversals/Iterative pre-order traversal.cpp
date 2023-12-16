//code:

#include <stack>

// TreeNode class structure
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

// Pre-order traversal (iterative)
vector<int> preOrder(TreeNode<int> *root){
    vector<int> ans;

    stack<TreeNode<int> *> s;
    s.push(root);

    while (!s.empty()){
        TreeNode<int> *cur = s.top();
        s.pop();

        ans.push_back(cur->data);
        if (cur->right) s.push(cur->right);  
        if(cur->left) s.push(cur->left);
    }
    return ans;
}
