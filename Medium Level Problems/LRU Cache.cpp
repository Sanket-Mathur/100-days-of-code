// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    class node {
        public:
        int key;
        int value;
        node *prev;
        node *next;
        
        node(int key, int value) {
            this->key = key;
            this->value = value;
        }
    };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*> table;
    
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        this->cap = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node *temp) {
        node *dummy = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next = dummy;
        dummy->prev = temp;
    }
    
    void deletenode(node *temp) {
        node *delnext = temp->next;
        node *delprev = temp->prev;
        delnext->prev = delprev;
        delprev->next = delnext;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if (table.find(key) == table.end())
            return -1;
            
        node *res = table[key];
        table.erase(key);
        
        int ans = res->value;
        
        deletenode(res);
        addnode(res);
        
        table[key] = head->next;
        
        return ans;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if (table.find(key) != table.end()) {
            node *exist = table[key];
            table.erase(key);
            deletenode(exist);
        }
        
        if (table.size() == cap) {
            table.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        table[key] = head->next;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends