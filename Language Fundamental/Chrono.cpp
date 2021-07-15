#include <iostream>
#include <chrono>
#include <windows.h>

using namespace std;

int main() {
    auto start = chrono::system_clock::now();
    Sleep(3000);
    auto end = chrono::system_clock::now();

    chrono::duration<double> elapsed = end - start;
    cout << "Elapsed time: " << elapsed.count() << "s";

    return 0;
}