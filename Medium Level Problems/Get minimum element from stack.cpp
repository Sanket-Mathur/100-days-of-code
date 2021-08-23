// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;

       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }

}


// } Driver Code Ends


/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

int min_ele;

/*returns min element from stack*/
int _stack :: getMin()
{
    if (s.empty())
        return -1;
    return min_ele;
}

/*returns poped element from stack*/
int _stack ::pop()
{
    if (s.empty())
        return -1;
    
    if (s.top() >= min_ele) {
        int t = s.top();
        s.pop();
        return t;
    } else {
        int temp = min_ele;
        min_ele = 2*min_ele - s.top();
        s.pop();
        return temp;
    }
}

/*push element x into the stack*/
void _stack::push(int x)
{
    if (s.empty()) {
        s.push(x);
        min_ele = x;
    } else if (x >= min_ele) {
        s.push(x);
    } else {
        s.push(2*x - min_ele);
        min_ele = x;
    }
}
