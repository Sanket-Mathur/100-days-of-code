#include <iostream>

using namespace std;

void f2(int x) throw(int) {
    cout << "Enter f2" << endl;
    if(x == 0) throw(x);
    cout << "Exit f2" << endl;
}
void f1(int x) throw (int) {
    cout << "Enter f1" << endl;
    f2(x);
    cout << "Exit f1" << endl;
}

int main() {
    // basic try - catch block
    try {
        cout << "Inside basic try block" << endl;
        throw 1;
    } catch (char e) {
        cout << "Character Exception caught" << endl;
    } catch (int e) {
        cout << "Integer Exception caught" << endl;
    } catch (...) {
        cout << "Unknown Exception caught" << endl;
    }

    // try - catch with function stack
    try {
        f1(0);
    } catch(int e) {
        cout << "Exception from function" << endl;
    }

    return 0;
}