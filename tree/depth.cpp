#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int Depth(TreeNode *root, int depth) {
        if (root == nullptr) {
            return depth;
        }
        int x = Depth(root->left, depth + 1);
        int y = Depth(root->right, depth + 1);

        return max(x, y);
    }

    int maxDepth(TreeNode *root) {
        return Depth(root, 0);
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
    int maxDepth = solution.maxDepth(root);
    cout << "Maximum depth of the binary tree: " << maxDepth << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
