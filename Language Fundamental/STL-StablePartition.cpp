#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool evenNumbers(int x) {
    return x % 2 == 0;
}

int main() {
    vector<int> numbers {2, 15, 4, 12, 32, 95, 73, 82};

    // partitioning on the basis of even odd numbers
    vector<int>::iterator bound = stable_partition(numbers.begin(), numbers.end(), evenNumbers);

    cout << "Even numbers" << endl;
    for(auto i = numbers.begin(); i != bound; ++i) {
        cout << *i << endl;
    }
    cout << endl;

    cout << "Odd numbers" << endl;
    for(auto i = bound; i != numbers.end(); ++i) {
        cout << *i << endl;
    }
    cout << endl;

    return 0;
}