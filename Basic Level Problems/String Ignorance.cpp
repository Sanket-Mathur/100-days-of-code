#include <bits/stdc++.h>
#define ll long long
using namespace std;

void stringIgnorance(string s) {
    unordered_set<char> set;
    for (auto i : s) {
        if (set.find(tolower(i)) == set.end()) {
            cout << i;
            set.insert(tolower(i));
        } else {
            set.erase(tolower(i));
        }
    }
    cout << endl;
}

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
	    string s;
	    
	    getline(cin, s);
	    stringIgnorance(s);
	}
	return 0;
}