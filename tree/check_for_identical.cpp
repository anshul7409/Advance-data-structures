#include <iostream>

using namespace std;

// Definition of BinaryTreeNode
template<typename T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;
    BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
};

template<typename T>
bool Same(BinaryTreeNode<T>* root1, BinaryTreeNode<T>* root2) {
    if (root1 == NULL || root2 == NULL) {
        return root1 == root2;
    }

    return root1->data == root2->data && Same(root1->left, root2->left) && Same(root1->right, root2->right);
}

template<typename T>
bool identicalTrees(BinaryTreeNode<T>* root1, BinaryTreeNode<T>* root2) {
    bool ans = Same(root1, root2);
    return ans;
}

int main() {
    // Create the first tree
    BinaryTreeNode<int>* root1 = new BinaryTreeNode<int>(1);
    root1->left = new BinaryTreeNode<int>(2);
    root1->right = new BinaryTreeNode<int>(3);
    root1->left->left = new BinaryTreeNode<int>(4);
    root1->left->right = new BinaryTreeNode<int>(5);

    // Create the second tree
    BinaryTreeNode<int>* root2 = new BinaryTreeNode<int>(1);
    root2->left = new BinaryTreeNode<int>(2);
    root2->right = new BinaryTreeNode<int>(3);
    root2->left->left = new BinaryTreeNode<int>(4);
    root2->left->right = new BinaryTreeNode<int>(5);

    // Check if the trees are identical
    bool areIdentical = identicalTrees(root1, root2);
    if (areIdentical) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }

    // Deallocate memory
    delete root1->left->right;
    delete root1->left->left;
    delete root1->right;
    delete root1->left;
    delete root1;

    delete root2->left->right;
    delete root2->left->left;
    delete root2->right;
    delete root2->left;
    delete root2;

    return 0;
}
