#include <iostream>
#include <valarray>

using namespace std;

int main() {
    int row = 3, col = 3;
    valarray<int> matrix(row * col);
    for(int i = 0; i < row * col; i++) {
        matrix[i] = i + 1;
    }

    // printing valarray
    int index = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << matrix[index++] << " ";
        }
        cout << endl;
    }

    // selecting and displaying diagnol of matrix
    valarray<int> diagnol = matrix[slice(0, col, col + 1)];
    cout << "Diagonal: " << endl;
    for(int i = 0; i < col; i++) {
        cout << diagnol[i] << " ";
    }
    cout << endl;

    return 0;
}