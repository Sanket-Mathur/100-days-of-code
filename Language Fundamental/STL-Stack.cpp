#include <iostream>
#include <stack>

using namespace std;

void print_stack(stack<char> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<char> operators;

    // insertion
    cout << "Inserting -, /, * and +" << endl;
    operators.push('-');
    operators.push('/');
    operators.push('*');
    operators.push('+');

    print_stack(operators);

    // deletion
    operators.pop();
    print_stack(operators);

    // size
    cout << "Size: " << operators.size() << endl;

    return 0;
}