#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node *left, *right;
    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node *root;
    BST() {
        root = nullptr;
    }
    void insert(int val) {
        if (!root) {
            root = new Node(val);
            return;
        }
        Node *prev = nullptr;
        Node *node = root;
        while (node) {
            prev = node;
            if (node->value > val) node = node->left;
            else node = node->right;
        }
        if (prev->value > val) {
            prev->left = new Node(val);
        } else {
            prev->right = new Node(val);
        }
    }
};
void preorder(Node *root) {
    if (root) {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}
void postorder(Node *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
}

int main() {
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(10);
    bst.insert(2);
    bst.insert(4);

    /*
             5
            / \
          3    10
         / \   / \
        2   4 X  X
       / \ / \
      X  X X X
    */

    preorder(bst.root);

    return 0;
}