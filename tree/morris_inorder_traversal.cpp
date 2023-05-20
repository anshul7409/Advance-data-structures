#include <iostream>
#include <vector>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                inorder.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};

// Helper function to create a binary tree
TreeNode* createNode(int val) {
    TreeNode* newNode = new TreeNode(val);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    // Create an instance of the Solution class
    Solution solution;

    // Perform inorder traversal
    vector<int> result = solution.inorderTraversal(root);

    // Print the inorder traversal result
    cout << "Inorder Traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


//for preorder traversal using morris traversal technique add push_back after line 16 and remove push_back from line 19