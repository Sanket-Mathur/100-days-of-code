// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        vector<int> inorder(in, in+n);
        vector<int> preorder(pre, pre+n);
        return build(inorder, preorder);
    }
    Node* build(vector<int> in, vector<int> pre) {
        if (pre.empty())
            return NULL;
            
        Node* root = new Node(pre[0]);
        
        int i = search(in, pre[0]);
        root->left = build(vector<int> (in.begin(), in.begin()+i), vector<int> (pre.begin()+1, pre.begin()+i+1));
        root->right = build(vector<int> (in.begin()+i+1, in.end()), vector<int> (pre.begin()+i+1, pre.end()));
        
        return root;
    }
    int search(vector<int> v, int key) {
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == key) {
                return i;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends