// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int arr[],int n)
{
    int c = 0, s_past = 0, max_s, temp;
    for (int i = 0; i < n; ++i) {
        c += arr[i];
    }
    for (int i = 0; i < n; ++i) {
        s_past += arr[i] * i;
    }
    
    max_s = s_past;
    for (int i = 1; i < n; ++i) {
        temp = s_past - c + arr[i-1]*n;
        max_s = max(max_s, temp);
        s_past = temp;
    }
    return max_s;
}