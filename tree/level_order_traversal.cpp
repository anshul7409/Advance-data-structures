#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
vector<T> getLevelOrder(BinaryTreeNode<T> *root) {
    vector<T> ans;
    if (root == nullptr) {
        return ans;
    }
    queue<BinaryTreeNode<T> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<T> *temp = q.front();
        q.pop();
        ans.push_back(temp->data);
        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
    return ans;
}

int main() {
    // Create a sample binary tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);

    vector<int> levelOrder = getLevelOrder(root);

    cout << "Level Order Traversal: ";
    for (int val : levelOrder) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
