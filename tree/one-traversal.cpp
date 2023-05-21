//inorder,preorder and postorder in one traversal


#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root) {
    stack<pair<BinaryTreeNode<int> *, int>> st;
    st.push({root, 1});
    vector<int> In, pre, post;
    if (root == NULL) {
        return {};
    }
    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        } else if (it.second == 2) {
            In.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        } else {
            post.push_back(it.first->data);
        }
    }
    vector<vector<int>> ans;
    ans.push_back(In);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}

int main() {
    // Create a binary tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);

    // Get the tree traversal
    vector<vector<int>> traversal = getTreeTraversal(root);

    // Print the results
    cout << "Inorder Traversal: ";
    for (int num : traversal[0]) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Preorder Traversal: ";
    for (int num : traversal[1]) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Postorder Traversal: ";
    for (int num : traversal[2]) {
        cout << num << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
