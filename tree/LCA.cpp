//naive approach O(n) time and space
// #include <iostream>
// #include <vector>

// using namespace std;

// // Definition of TreeNode
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// class Solution {
// public:    
//     bool Path(vector<TreeNode*>& ans, TreeNode* root, TreeNode* x) {
//         if (root == NULL) {
//             return false;
//         }
//         ans.push_back(root);
//         if (x->val == root->val) {
//             return true;
//         }
//         if (Path(ans, root->left, x) || Path(ans, root->right, x)) {
//             return true;
//         }
//         ans.pop_back();
//         return false;
//     }

//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode*> a;
//         vector<TreeNode*> b;
//         if (root == NULL) {
//             return NULL;
//         }
//         Path(a, root, p);
//         Path(b, root, q);
//         int i = 0, j = 0;
//         while (i < a.size() && j < b.size() && a[i] == b[j]) {
//             i++;
//             j++;
//         }
//         return a[i - 1];
//     }
// };

// int main() {
//     // Create the tree
//     TreeNode* root = new TreeNode(3);
//     root->left = new TreeNode(5);
//     root->right = new TreeNode(1);
//     root->left->left = new TreeNode(6);
//     root->left->right = new TreeNode(2);
//     root->left->right->left = new TreeNode(7);
//     root->left->right->right = new TreeNode(4);
//     root->right->left = new TreeNode(0);
//     root->right->right = new TreeNode(8);

//     Solution solution;

//     // Find the lowest common ancestor of nodes with values 5 and 1
//     TreeNode* lca = solution.lowestCommonAncestor(root, root->left, root->right);
//     if (lca != NULL) {
//         cout << "Lowest Common Ancestor: " << lca->val << endl;
//     } else {
//         cout << "Lowest Common Ancestor not found." << endl;
//     }

//     // Deallocate memory
//     delete root->right->right;
//     delete root->right->left;
//     delete root->left->right->right;
//     delete root->left->right->left;
//     delete root->left->right;
//     delete root->left->left;
//     delete root->right;
//     delete root->left;
//     delete root;

//     return 0;
// }

//efficient approach
#include <iostream>

using namespace std;

// Definition of TreeNode
template<typename T>
struct TreeNode {
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode(T x) : data(x), left(NULL), right(NULL) {}
};

template<typename T>
int FindLCA(TreeNode<T>* root, T x, T y) {
    if (root == NULL || root->data == x || root->data == y) {
        if (root == NULL) {
            return -1;
        }
        return root->data;
    }

    int p = FindLCA(root->left, x, y);
    int q = FindLCA(root->right, x, y);

    if (p == -1) {
        return q;
    } else if (q == -1) {
        return p;
    } else {
        return root->data;
    }
}

template<typename T>
int lowestCommonAncestor(TreeNode<T>* root, T x, T y) {
    if (root == NULL) {
        return -1;
    }
    return FindLCA(root, x, y);
}

int main() {
    // Create the tree
    TreeNode<int>* root = new TreeNode<int>(3);
    root->left = new TreeNode<int>(5);
    root->right = new TreeNode<int>(1);
    root->left->left = new TreeNode<int>(6);
    root->left->right = new TreeNode<int>(2);
    root->left->right->left = new TreeNode<int>(7);
    root->left->right->right = new TreeNode<int>(4);
    root->right->left = new TreeNode<int>(0);
    root->right->right = new TreeNode<int>(8);

    int x = 5;
    int y = 1;

    // Find the lowest common ancestor of nodes with values x and y
    int lca = lowestCommonAncestor(root, x, y);
    if (lca != -1) {
        cout << "Lowest Common Ancestor: " << lca << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    // Deallocate memory
    delete root->right->right;
    delete root->right->left;
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
