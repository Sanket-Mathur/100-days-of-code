#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // sorting the alphabets ignoring the index order
    vector<string> alphabets {"1. C", "2. E", "3. D", "4. A", "5. B"};

    sort(alphabets.begin(), alphabets.end(), [](const string& a, const string& b) -> bool {
        return a[3] < b[3];
    });

    for(auto i : alphabets) {
        cout << i << endl;
    }

    // function to square number
    auto square = [](int i) {
        return i * i;
    };
    cout << "pow(25,2) = " << square(25) << endl;

    // counting numbers in vector greated to equal to 10
    vector<int> numbers {26, 10, 30, 5, 2, 12};
    int greaterThan5 = count_if(numbers.begin(), numbers.end(), [](int i) {
        return (i > 10);
    });
    cout << "Count of numbers in vector greated than 10 is " << greaterThan5 << endl;

    return 0;
}