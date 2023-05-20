#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
};

class FullBinaryTree {
public:
    Node* root;

    FullBinaryTree() {
        root = NULL;
    }

    void insert(int value) {
        Node* new_node = new Node(value);
        if (!root) {
            root = new_node;
        }
        else {
            Node* current_node = root;
            while (true) {
                if (!current_node->left) {
                    current_node->left = new_node;
                    break;
                }
                else if (!current_node->right) {
                    current_node->right = new_node;
                    break;
                }
                else {
                    // Traverse to the next level using a queue-based approach
                    if (current_node->left && !current_node->right) {
                        current_node = current_node->right;
                    }
                    else {
                        current_node = current_node->left;
                    }
                }
            }
        }
    }
};

int main() {
    FullBinaryTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);

    // Print the values of the tree
    cout << "Values of the tree: ";
    cout << tree.root->value << " ";
    cout << tree.root->left->value << " ";
    cout << tree.root->right->value << " ";
    cout << tree.root->left->left->value << endl;

    // Clean up the allocated memory
    delete tree.root->left->left;
    delete tree.root->right;
    delete tree.root->left;
    delete tree.root;

    return 0;
}
