// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int from, int to, int aux) {
        long long moves = 0;
        towerOfHanoi(N, from, to, aux, moves);
        return moves;
    }
    
    void towerOfHanoi(int N, int from, int to, int aux, long long &moves) {
        if (N == 1) {
            cout << "move disk 1 from rod " << from << " to rod " << to << endl;
            moves++;
            return;
        }
        
        towerOfHanoi(N-1, from, aux, to, moves);
        
        cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
        moves++;
        
        towerOfHanoi(N-1, aux, to, from, moves);
    }
};

// { Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.  // } Driver Code Ends