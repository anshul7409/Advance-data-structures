#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void LeftView(Node* node, int level, vector<int>& ds) {
    if (node == NULL) {
        return;
    }
    if (level == ds.size()) {
        ds.push_back(node->data);
    }
    LeftView(node->left, level + 1, ds);
    LeftView(node->right, level + 1, ds);
}

void RightView(Node* node, int level, vector<int>& ds) {
    if (node == NULL) {
        return;
    }
    if (level == ds.size()) {
        ds.push_back(node->data);
    }
    RightView(node->right, level + 1, ds);
    RightView(node->left, level + 1, ds);
}

int main() {
    // Create a sample binary tree
    Node* root = new Node();
    root->data = 1;

    Node* node2 = new Node();
    node2->data = 2;

    Node* node3 = new Node();
    node3->data = 3;

    Node* node4 = new Node();
    node4->data = 4;

    Node* node5 = new Node();
    node5->data = 5;

    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = NULL;
    node3->right = NULL;
    node4->left = NULL;
    node4->right = NULL;
    node5->left = NULL;
    node5->right = NULL;

    // Perform left view
    vector<int> leftView;
    LeftView(root, 0, leftView);

    // Perform right view
    vector<int> rightView;
    RightView(root, 0, rightView);

    // Print left view
    cout << "Left View: ";
    for (int i = 0; i < leftView.size(); i++) {
        cout << leftView[i] << " ";
    }
    cout << endl;

    // Print right view
    cout << "Right View: ";
    for (int i = 0; i < rightView.size(); i++) {
        cout << rightView[i] << " ";
    }
    cout << endl;

    // Clean up the allocated memory
    delete root;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    return 0;
}
