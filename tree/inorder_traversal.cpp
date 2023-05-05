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
    void inorderTraverse(TreeNode * root,vector<int> & ans)
    {
        if(root == NULL){
            return;
        }
        inorderTraverse(root->left,ans);
        ans.push_back(root->val);
        inorderTraverse(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> ans;
       inorderTraverse(root,ans);
       return ans;
    }
};

//for iterative solution, refer to morris_inorder_traversal.cpp
//for preorder traversal, change the order of push_backs by pushing root first and then left and right
//for postorder traversal, change the order of push_backs by pushing root last and then left and right