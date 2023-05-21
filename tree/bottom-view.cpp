#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition of Binary Tree Node
template<typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to get the bottom view of a binary tree
vector<int> bottomView(BinaryTreeNode<int> *root) {
    vector<int> ans;
    if (root == NULL) {
        return {};
    }
    map<int, int> mp;
    queue<pair<BinaryTreeNode<int>*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        BinaryTreeNode<int>* node = it.first;
        int line = it.second;
        mp[line] = node->data;
        if (node->left != NULL) {
            q.push({node->left, line - 1});
        }
        if (node->right != NULL) {
            q.push({node->right, line + 1});
        }
    }
    for (auto it : mp) {
        ans.push_back(it.second);
    }
    return ans;
}

// Test the bottomView function
int main() {
    // Create the binary tree
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(20);
    root->left = new BinaryTreeNode<int>(8);
    root->right = new BinaryTreeNode<int>(22);
    root->left->left = new BinaryTreeNode<int>(5);
    root->left->right = new BinaryTreeNode<int>(3);
    root->right->left = new BinaryTreeNode<int>(4);
    root->right->right = new BinaryTreeNode<int>(25);
    root->left->right->left = new BinaryTreeNode<int>(10);
    root->left->right->right = new BinaryTreeNode<int>(14);

    // Get the bottom view of the binary tree
    vector<int> result = bottomView(root);

    // Print the bottom view
    cout << "Bottom View: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // Deallocate memory
    // ...

    return 0;
}
