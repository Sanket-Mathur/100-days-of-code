#include <iostream>
#include <random>
#include <time.h>
#include <string.h>

using namespace std;

int main() {
    // simple pseudo random number generator
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        cout << rand() % 10 << " ";
    }
    cout << endl;

    // true random number generator
    random_device crypto_random_generator;
    uniform_int_distribution<int> int_distribution(0,9);

    int actual_distribution[10] = {0,0,0,0,0,0,0,0,0,0};
    for(int i = 0; i < 10000; i++) {
        int result = int_distribution(crypto_random_generator);
        actual_distribution[result]++;
    }
    for(int i = 0; i < 10; i++) {
        cout << actual_distribution[i] << " ";
    }
    cout << endl;

    // pseudo random number generator
    memset(actual_distribution, 0, sizeof(actual_distribution));
    default_random_engine pseudo_random_generator;
    for(int i = 0; i < 10000; i++) {
        int result = int_distribution(pseudo_random_generator);
        actual_distribution[result]++;
    }
    for(int i = 0; i < 10; i++) {
        cout << actual_distribution[i] << " ";
    }
    cout << endl;

    return 0;
}