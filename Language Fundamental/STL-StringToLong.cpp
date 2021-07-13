#include <iostream>
#include <string>

using namespace std;

int main() {
    // hexadecimal
    string s = "5F7";
    cout << "4F7 converted to unsigned long with base 16: " << stoul(s, nullptr, 16) << endl;

    // decimal
    s = "294";
    unsigned long converted = stoul(s, nullptr, 10);
    cout << "294 converted to unsigned long with base 10: " << converted << endl;

    // octal
    s = "23634563457";
    cout << "23634563457 converted to unsigned long long with base 8: " << stoull(s, nullptr, 8) << endl;

    // binary
    s = "1011";
    cout << "1011 converted to unsigned long with base 2: " << stoul(s, nullptr, 2) << endl;

    return 0;
}