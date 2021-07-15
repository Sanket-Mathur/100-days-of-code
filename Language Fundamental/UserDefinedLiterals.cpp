#include <iostream>

using namespace std;

// kilometers
long double operator"" _km(long double x) {
    return x * 1000;
}

// meters
long double operator"" _m(long double x) {
    return x;
}

// centimeter
long double operator"" _cm(long double x) {
    return x / 100;
}

// milimeter
long double operator"" _mm(long double x) {
    return x / 1000;
}

int main() {
    long double distance = 0;

    // adding weigths to basket
    distance += 2.5_km;
    distance += 250.0_m;
    distance += 500.0_cm;
    distance += 2000.0_mm;

    cout << "Total distance: " << distance << "m" << endl;

    return 0;
}

/*
UDL can only be applied to these datatypes but they can return any type
char const*
unsigned long long
long double
char const*, std::size_t
wchar_t const*, std::size_t
char16_t const*, std::size_t
char32_t const*, std::size_t
*/