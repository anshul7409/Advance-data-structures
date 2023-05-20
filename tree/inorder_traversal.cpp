#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void inorderTraverse(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        inorderTraverse(root->left, ans);
        ans.push_back(root->val);
        inorderTraverse(root->right, ans);
    }

    void preorderTraverse(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        ans.push_back(root->val);
        preorderTraverse(root->left, ans);
        preorderTraverse(root->right, ans);
    }

    void postorderTraverse(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        postorderTraverse(root->left, ans);
        postorderTraverse(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderTraverse(root, ans);
        return ans;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorderTraverse(root, ans);
        return ans;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorderTraverse(root, ans);
        return ans;
    }
};

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create an instance of the Solution class
    Solution solution;

    // Perform inorder traversal
    vector<int> inorder = solution.inorderTraversal(root);

    // Perform preorder traversal
    vector<int> preorder = solution.preorderTraversal(root);

    // Perform postorder traversal
    vector<int> postorder = solution.postorderTraversal(root);

    // Print inorder traversal
    cout << "Inorder traversal: ";
    for (int i = 0; i < inorder.size(); i++) {
        cout << inorder[i] << " ";
    }
    cout << endl;

    // Print preorder traversal
    cout << "Preorder traversal: ";
    for (int i = 0; i < preorder.size(); i++) {
        cout << preorder[i] << " ";
    }
    cout << endl;

    // Print postorder traversal
    cout << "Postorder traversal: ";
    for (int i = 0; i < postorder.size(); i++) {
        cout << postorder[i] << " ";
    }
    cout << endl;

    // Clean up the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

//for iterative solution, refer to morris_inorder_traversal.cpp
//for preorder traversal, change the order of push_backs by pushing root first and then left and right
//for postorder traversal, change the order of push_backs by pushing root last and then left and right