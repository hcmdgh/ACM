#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    cin.ignore(1024, '\n');
    while (N--) {
        string str;
        getline(cin, str);
        stack<bool> _stack;
        bool valid = true;
        for (char ch : str) {
            if (ch == '(')
                _stack.emplace(true);
            else if (ch == '[')
                _stack.emplace(false);
            else if (ch == ')') {
                if (_stack.empty()) {
                    valid = false;
                    break;
                }
                bool top = _stack.top();
                _stack.pop();
                if (!top) {
                    valid = false;
                    break;
                }
            } else if (ch == ']') {
                if (_stack.empty()) {
                    valid = false;
                    break;
                }
                bool top = _stack.top();
                _stack.pop();
                if (top) {
                    valid = false;
                    break;
                }
            }
        }
        valid = valid && _stack.empty();
        if (valid) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
