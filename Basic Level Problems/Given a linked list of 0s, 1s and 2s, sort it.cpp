// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node *zero = NULL;
        Node *one = NULL;
        Node *two = NULL;
        sortNode(head, &zero, &one, &two);
        
        Node *node = zero;
        while (node && node->next) {
            node = node->next;
        }
        
        if (node) node->next = one;
        else node = one;
        while (node && node->next) {
            node = node->next;
        }
        
        if (node) node->next = two;
        else node = two;
        while (node && node->next) {
            node = node->next;
        }
       
        return zero;
    }
    void sortNode(Node *node, Node **zero, Node **one, Node **two) {
        if (!node) {
            return;
        }
        sortNode(node->next, zero, one, two);
        if (node->data == 0) {
            node->next = *zero;
            *zero = node;
        } else if (node->data == 1) {
            node->next = *one;
            *one = node;
        } else {
            node->next = *two;
            *two = node;
        }
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends