// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverse(first);
        second = reverse(second);
        
        Node *head = new Node(-1);
        Node *last = head;
        add(first, second, last, 0);
        
        head = reverse(head->next);
        return head;
    }
    Node* reverse(Node* node) {
        Node* prev = NULL;
        Node* next;
        while (node->next) {
            next = node->next;
            node->next = prev;
            
            prev = node;
            node = next;
        }
        node->next = prev;
        return node;
    }
    void add(Node* first, Node* second, Node* last, int carry) {
        if (!first && !second) {
            if (carry) {
                last->next = new Node(carry);
            }
            return;
        } else if (!second) {
            int addition = first->data + carry;
            int c = 0;
            if (addition >= 10) {
                c = addition / 10;
                addition %= 10;
            }
            last->next = new Node(addition);
            add(first->next, second, last->next, c);
        } else if (!first) {
            int addition = second->data + carry;
            int c = 0;
            if (addition >= 10) {
                c = addition / 10;
                addition %= 10;
            }
            last->next = new Node(addition);
            add(first, second->next, last->next, c);
        } else {
            int addition = first->data + second->data + carry;
            int c = 0;
            if (addition >= 10) {
                c = addition / 10;
                addition %= 10;
            }
            last->next = new Node(addition);
            add(first->next, second->next, last->next, c);
        }
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends