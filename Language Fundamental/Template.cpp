#include <iostream>

using namespace std;

void print() {
    cout << "\nEmpty Function to stop the recursive call at the end of the argument list" << endl; 
}

template<typename T, typename... Types>
void print(T var, Types... args) {
    cout << var << endl;
    print(args...);
}

int main() {
    print(1,2,3, "This is a string", 3.12, false);

    return 0;
}