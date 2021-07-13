#include <iostream>
#include <algorithm>
#include <vector>
#include <random> // for default_random_engine

using namespace std;

int main() {
    vector<int> series {1,2,3,4,5,6,7,8,9,10};
    shuffle(series.begin(), series.end(), default_random_engine(0));

    for(auto i : series) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}