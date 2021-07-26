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
    Node* remove(Node* node,int val) {
        if (!node) {
            cout << "Cannot delete" << endl;
            return nullptr;
        }
        if (val < node->value) {
            node->left = remove(node->left, val);
        } else if (val > node->value) {
            node->right = remove(node->right, val);
        } else {
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            } else if (!node->right || !node->left) {
                Node* temp = node->right ? node->right : node->left;
                delete node;
                return temp;
            } else {
                Node* inorderSuccessor = node->right;
                while (inorderSuccessor && inorderSuccessor->left) {
                    inorderSuccessor = inorderSuccessor->left;
                }

                node->value = inorderSuccessor->value;
                node->right = remove(node->right, inorderSuccessor->value);
            }
        }
    }
    void preorder(Node *node) {
        if (node) {
            cout << node->value << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    void inorder(Node *node) {
        if (node) {
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }
    }
    void postorder(Node *node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->value << " ";
        }
    }
};

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

    bst.preorder(bst.root);
    cout << endl;

    bst.remove(bst.root, 3);

    /*
             5
            / \
          4    10
         / \   / \
        2   X X  X
       / \
      X  X
    */

    bst.preorder(bst.root);

    return 0;
}