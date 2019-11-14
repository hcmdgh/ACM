#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    char ch;
    stack<int> s;
    int num = 0;
    while ((cin >> ch) && ch != '@') {
        if (ch >= '0' && ch <= '9') {
            num = num * 10 + ch - '0';
        } else if (ch == '.') {
            s.push(num);
            num = 0;
        } else if (ch != ' ') {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            int result;
            switch (ch) {
                case '+':
                    result = op2 + op1;
                    break;
                case '-':
                    result = op2 - op1;
                    break;
                case '*':
                    result = op2 * op1;
                    break;
                case '/':
                    result = op2 / op1;
                    break;
            }
            s.push(result);
        }
    }
    cout << s.top() << endl;

    return 0;
}