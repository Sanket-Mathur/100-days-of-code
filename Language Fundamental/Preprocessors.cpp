#include <iostream>

// using macro preprocessor
#define MAX(a, b) (a > b ? a : b)
#define HUMAN 10

using namespace std;

int main() {
    // testing macros 
    cout << MAX(3, 4) << endl;

    // using conditional proprocessor
    #ifdef HUMAN
        cout << "HUMAN is defined. The value stored is " << HUMAN << endl;
    #endif
    
    // undefining macro
    #undef HUMAN
    #ifdef HUMAN
        cout << "HUMAN is defined. The value stored is " << HUMAN << endl;
    #endif



    return 0;
}