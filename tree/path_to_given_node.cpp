#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool path(TreeNode* A, vector<int>& ans, int B) {
    if (A == NULL) {
        return false;
    }

    ans.push_back(A->val);

    if (A->val == B) {
        return true;
    }

    if (path(A->left, ans, B) || path(A->right, ans, B)) {
        return true;
    }
    ans.pop_back();
    return false;
}

vector<int> solve(TreeNode* A, int B) {
    vector<int> ans;
    path(A, ans, B);
    return ans;
}

// Utility function to create a new binary tree node
TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    node->left = node->right = NULL;
    return node;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int target = 5;
    vector<int> result = solve(root, target);

    cout << "Path to node " << target << ": ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
