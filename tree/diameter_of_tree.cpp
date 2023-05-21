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
    int Depth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left = Depth(root->left);
        int right = Depth(root->right);

        int ans = max(left, right) + 1;
        return ans;
    }

    int diameter(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int ld = diameter(root->left);
        int rd = diameter(root->right);
        int com = Depth(root->left) + Depth(root->right) + 1;
        int ans = max(com, max(ld, rd));
        return ans;
    }

    int diameterOfBinaryTree(TreeNode *root) {
        int dm = diameter(root);
        return dm - 1;
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
    int diameter = solution.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree: " << diameter << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
