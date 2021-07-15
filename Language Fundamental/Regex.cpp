#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    string str = "This is my email: rajeev.sanket@gmail.com";
    regex r("[a-zA-Z0-9.]*@[a-z]*.[a-z]*");

    // checking if a email exists in the string
    if (regex_match(str, r)) {
        cout << "Email exists in the string" << endl;
    } else {
        cout << "Email does not exist in the string" << endl;
    }

    // extracting the email form the string
    smatch m;
    regex_search(str, m, r);

    for (auto x : m) {
        cout << x << endl;
    }

    // replacing my email with temporary email
    string result;
    regex_replace(back_inserter(result), str.begin(), str.end(), r, "test123@example.com");
    cout << "Modified string: \"" << result << "\"" << endl;

    return 0;
}