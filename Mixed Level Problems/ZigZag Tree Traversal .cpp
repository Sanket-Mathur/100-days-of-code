// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<queue<int>> a;
        vector<stack<int>> b;
        
        level(root, a, b, 0);
        
        vector<int> result;
        
        int size = a.size() > b.size() ? a.size() * 2 - 1: b.size() * 2;
        for (int i = 0; i < size; ++i) {
            if (i % 2 == 0) {
                queue<int> temp = a[(int)(i / 2)];
                while (!temp.empty()) {
                    result.push_back(temp.front());
                    temp.pop();
                }
            } else {
                stack<int> temp = b[(int)(i / 2)];
                while (!temp.empty()) {
                    result.push_back(temp.top());
                    temp.pop();
                }
            }
        }
        
        return result;
    }
    
    void level(Node* root, vector<queue<int>> &a, vector<stack<int>> &b, int lvl) {
        if (!root)
            return;
            
        if (lvl % 2 == 0) {
            if (a.size() == (int)(lvl / 2)) {
                queue<int> temp;
                a.push_back(temp);
            }
            
            a[(int)(lvl / 2)].push(root->data);
        } else {
            if (b.size() == (int)(lvl / 2)) {
                stack<int> temp;
                b.push_back(temp);
            }
            
            b[(int)(lvl / 2)].push(root->data);
        }
        
        level(root->left, a, b, lvl+1);
        level(root->right, a, b, lvl+1);
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.zigZagTraversal(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    }
    return 0;
}
  // } Driver Code Ends