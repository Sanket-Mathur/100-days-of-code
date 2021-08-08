#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

void solve(string str[], int n) {
    unordered_map<string, int> count;
    
    for (int i = 0; i < n; ++i) {
        if (count.find(str[i]) == count.end()) {
            count.insert(pair<string, int> (str[i], 1));
        } else {
            count.find(str[i])->second++;
        }
    }
    
    int max = 0;
    for (auto i : count) {
        if (i.second > max) {
            max = i.second;
        }
    }
    
    set<string> highest;
    for (auto i : count) {
        if (i.second == max) {
            highest.insert(i.first);
        }
    }
    
    cout << *highest.begin() << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n;
	    cin >> n;
	    
	    string str[n];
	    for (int i = 0; i < n; ++i) {
	        cin >> str[i];
	    }
	    
	    solve(str, n);
	}
	return 0;
}