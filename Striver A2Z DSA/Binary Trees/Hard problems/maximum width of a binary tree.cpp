/*
Problem statement:

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level 
are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.
*/



/*
Approach:

Width of a tree is the distance between leftmost and rightmost nodes ath the last level.
To find width, we need to have proper indexing to the nodes, and once we have numbers of leftMost and rightMost nodes, we can find the width as:
width = (rightMostNo- leftMostNo+ 1) 

We will find that using level-order traversal as the concept is related to the levels of the tree.
We will use a queue and two loops, indexing will be starting from 0, and for children it will be as:
leftChild= (i*2 +1) and rightChild= (i*2 +2)

Thus, we can calculate width & returning ans finding max width for each level.
Also, in indexing, we have to consider null nodes as well as they also contribute to the width.

Now, in certain cases where the tree might be skewed, we might end up having int overflow as we are multiplying by 2 for 
child nodes at each level.
TO avoid this, we need to convert the numbering & now, whenever we are assigning index for its children, take parent node as:
(i-curMin) rather than i, where curMin is the leftMost index.
*/


/*
Algorithm:

We will take a queue of pair<int, node> and push the root node along with index 0.
traverse the tree using a level order traversal.
In the level order traversal set another loop to run for the size of the queue, so that we visit the same level nodes inside it.
Before a level starts, use a variable(say curMin) to store the index of the first node.
assign an index to every node, and to its children as described above.
When the inner loop is at the first node of a level, store its index in another variable(sayleftMost)
When the inner loop is at the last node of a level, store its index in another variable(say rightMost)
After a level in the outer loop, calculate the width of the level as (rightMost – leftMost +1).
return the maximum width as the answer.
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

#define ll long long

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int ans=0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});

        while(!q.empty()){
            int size= q.size();
            int mmin= q.front().second;

            int first, last;
            for(int i=0; i<size; i++){
                ll cur= q.front().second - mmin;
                TreeNode* node= q.front().first;
                q.pop();

                if(i==0) first=cur;
                if(i==size-1) last= cur;

                if(node->left) q.push({node->left, cur*2+1});
                if(node->right) q.push({node->right, cur*2+2});
            }
            ans= max(ans, last-first+1);
        }
        return ans;
    }
};


/*
Problem variation:

in the above approach, we had to consider null nodes as well in counting the width of the tree, in a variation of this problem,
where we dont need to consider null nodes, and just find out the maximum number of nodes which are present at a level, then we can
apply simple bfs and calculate the total number of elements in the queue for that level and then traverse further.
*/

//code:

int getMaxWidth(TreeNode<int> *root)
{
    int ans=0;
    if(!root) return 0;

    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        int sz= q.size();
        //found out the max of elements at a particular level
        ans= max(ans, sz);

        for(int i=0; i<sz; i++){
            TreeNode<int>* front= q.front();
            q.pop();

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
    return ans;
}
