/*
Problem variation 1:
Given a node in a binary tree, print the path from root to that node in the tree.
*/

/*
Approach:

Start traversing from root using inorder traversal, because inorder traversals are easier, clean to write code.

From root, if we use recursion, then we will first go to all left and then return and go to the right call in inorder traversal.
First, travese from root to left, if the node is not of the given value, add the current node to ds and traverse further left till null.
If the null is reached but we didn't get the desired node, while returning from left, return value false and if false is returned,
remove the node of current call from the array while returning to the previous call.
Now, traverse to right(inorder) and check if the node is found, if the node of the current call is desired node, then return true,
if true is returned, do not remove the nodes from array in this case.
*/

//code:

bool getPath(Node* root, vector<int>& arr, int x){
  if(!root) return false;

  arr.push_back(root->val);

  if(root->val == x) return true;

  if(getPath(root->left, arr, x) || getPath(root->right, arr, x) return true;
  return false;
}

vector<int> solve(Node* A, int B){
  vector<int> arr;
  if(!A) return arr;

  getPath(A, arr, B);
  return arr;
}


/*
Problem variation 2:
Print all paths from root to lead nodes.

Approach: same as above just keep adding nodes at each level
*/

//code:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void getPath(TreeNode* root, vector<string>& ans, string str){

    if(!root->left && !root->right){
        string s= to_string(root->val);
        ans.push_back(str+s);
        return;
    }

    string s= to_string(root->val);
    if(root->left) getPath(root->left, ans, str+s+"->");
    if(root->right) getPath(root->right, ans, str+s+"->");

    return;
}

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;

        getPath(root, ans, "");
        return ans;
    }
};

