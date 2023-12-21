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

//In-order traversal using iterative approach (stack)

//code 1:

vector<int> getInOrderTraversal(TreeNode *root){
    vector<int> answer;

    if (root == NULL) return answer;

    stack<TreeNode *> s;
    TreeNode *current = root;

    while (current != NULL || !s.empty()){
        while (current != NULL){
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();

        answer.push_back(current->data);
        current = current->right;
    }
    
    return answer;
}


//code 2:

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* node= root;
        vector<int> ans;

        while(true){
            if(node) {
                stk.push(node);
                node= node->left;
            }else{
                if(stk.empty()) break;

                node= stk.top();
                stk.pop();
                ans.push_back(node->val);
                
                node= node->right;
            }
        }
        return ans;
    }
};
