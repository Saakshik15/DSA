// Level-order traversal: traverse the tree level by level

//code: (Coding Ninjas)

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

// Level-order traversal
vector<int> levelOrder(TreeNode<int> * root){    
    vector<int> ans;
    queue<TreeNode<int>*> q;

    q.push(root);

    while(!q.empty()){
        TreeNode<int>* currentNode = q.front();
        q.pop();
        ans.push_back(currentNode->data);
        if(currentNode->left) q.push(currentNode->left);
        if(currentNode->right) q.push(currentNode->right);
    }
    return ans;
}

//code: (Leetcode)

//each level is stored in a different vector here and we have to return a vector<vector<int>> 

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size= q.size();
            vector<int> level;

            for(int i=0; i<size; i++){
                TreeNode* node= q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
