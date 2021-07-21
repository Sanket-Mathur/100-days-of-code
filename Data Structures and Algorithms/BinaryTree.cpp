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
    Node *root = new Node(5);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(15);
    root->right->left = new Node(40);
    root->right->right = new Node(4);

    /*
             5
            / \
         10    20
        /  \   / \
       15  X 40   4
      / \   / \  / \
     X   X X  X X  X
    */

    cout << "Preorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << endl;

    return 0;
}