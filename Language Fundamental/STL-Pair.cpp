#include <iostream>
#include <utility>
#include <string>
#include <time.h>

using namespace std;

void print_pair(pair<long long int, string> p) {
    cout << p.first << " " << p.second << endl;
}

int main() {
    srand(time(0));

    pair<long long int, string> user;
    user.first = rand() % 1000000000;
    user.second = "Bob";
    print_pair(user);

    pair<long long int, string> user_duplitcate(user);
    print_pair(user_duplitcate);

    pair<long long int, string> admin(0, "Sanket Mathur");
    print_pair(admin);

    return 0;
}