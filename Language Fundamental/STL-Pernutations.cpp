#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // using next_permutation hence we need structure sorted in ascending order
    vector<int> v{1,2,3,4};

    int count = 0;
    do {
        cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
        ++count;
    } while (next_permutation(v.begin(), v.end()));
    cout << "Total Permutations: " << count << endl;

    // using prev_permutation hence we need structure sorted in descending order
    v = {1,2,3,4};
    sort(v.begin(), v.end(), greater<int>());

    count = 0;
    do {
        cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
        ++count;
    } while (prev_permutation(v.begin(), v.end()));
    cout << "Total Permutations: " << count << endl;

    return 0;
}