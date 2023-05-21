#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int Check(TreeNode *root, bool &ans) {
        if (root == nullptr) {
            return 0;
        }
        int lh = Check(root->left, ans);
        if (lh == -1) {
            return -1;
        }
        int rh = Check(root->right, ans);
        if (rh == -1) {
            return -1;
        }
        if (abs(rh - lh) > 1) {
            return -1;
        }
        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        bool ans = true;
        int x = Check(root, ans);
        if (x == -1) {
            return false;
        }
        return true;
    }
};

int main() {
    // Create a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    bool balanced = solution.isBalanced(root);
    cout << "Is the binary tree balanced? " << (balanced ? "Yes" : "No") << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
