#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct TreeNode {
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

bool isLeaf(TreeNode<int>* root) {
    return !root->left && !root->right;
}

void addLeftBoundary(TreeNode<int>* root, vector<int>& res) {
    TreeNode<int>* cur = root->left;
    while (cur) {
        if (!isLeaf(cur))
            res.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void addRightBoundary(TreeNode<int>* root, vector<int>& res) {
    TreeNode<int>* cur = root->right;
    vector<int> tmp;
    while (cur) {
        if (!isLeaf(cur))
            tmp.push_back(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    for (int i = tmp.size() - 1; i >= 0; --i) {
        res.push_back(tmp[i]);
    }
}

void addLeaves(TreeNode<int>* root, vector<int>& res) {
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaves(root->left, res);
    if (root->right)
        addLeaves(root->right, res);
}

vector<int> traverseBoundary(TreeNode<int>* root) {
    vector<int> res;
    if (!root)
        return res;
    if (!isLeaf(root)) {
        res.push_back(root->data);
    }
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}

int main() {
    // Create a sample binary tree
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);
    root->left->right->left = new TreeNode<int>(8);
    root->left->right->right = new TreeNode<int>(9);
    root->right->left->left = new TreeNode<int>(10);
    root->right->left->right = new TreeNode<int>(11);

    // Traverse the boundary of the binary tree
    vector<int> boundary = traverseBoundary(root);

    // Print the boundary elements
    cout << "Boundary Elements: ";
    for (int num : boundary) {
        cout << num << " ";
    }
    cout << endl;

    // Clean up the memory
    // ...

    return 0;
}
