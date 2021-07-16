// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void add_pair(vector<pair<string,pair<int,int> > > &A,string str,int x,int y);
int get_size(vector<pair<string,pair<int,int> > > &A);
void print_values(vector<pair<string,pair<int,int> > > &A);
void sort_pair(vector<pair<string,pair<int,int> > > &A);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		vector<pair<string,pair<int,int> > > A;
		int q;
		cin>>q;
		while(q--)
		{
			char c;
			cin>>c;
			if(c=='a')
			{
				string name;
				cin>>name;
				int x,y;
				cin>>x>>y;
				add_pair(A,name,x,y);
			}
			if(c=='b')
			{
				cout<<get_size(A)<<" ";
			}
			if(c=='c')
			{
				print_values(A);
			}
			if(c=='d')
			{
			 	sort_pair(A);
			}
		
		
		}
cout<<endl;
	}
	return 0;
}// } Driver Code Ends


/* Inserts a pair  <string,   pair<x, y> > >    into the vector A */
void add_pair(vector<pair<string,pair<int,int> > > &A, string str, int x, int y)
{
    pair<int, int> internal(x, y);
    pair<string, pair<int, int>> element(str, internal);
    A.push_back(element);
}

/* Returns the size of the vector A */
int get_size(vector<pair<string,pair<int,int> > > &A)
{
     return A.size();
}

/* Prints space separated values of vector A */
void print_values(vector<pair<string,pair<int,int> > > &A)
{
     for(auto i : A) {
         cout << i.first << " " << i.second.first << " " << i.second.second << " ";
     }
}

/* Sorts the vector A based on value x and y*/
void sort_pair(vector<pair<string,pair<int,int> > > &A)
{
     sort(A.begin(), A.end(), [](const pair<string,pair<int,int>>& a, const pair<string,pair<int,int>>& b) -> bool {
         if (a.second.first < b.second.first) return true;
         if (a.second.first > b.second.first) return false;
         if (a.second.second < b.second.second) return true;
         return false;
     });
}