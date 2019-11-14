#include <iostream>
using namespace std;

const long long MAX_NUM = 4294967295;

int main() {
    ios::sync_with_stdio(false);
    int L;
    cin >> L;
    string command;
    long long stack[100000];
    int stack_size = 1;
    stack[0] = 1;
    long long result = 0;
    for (int i = 0; i < L; ++i) {
        cin >> command;
        if (command == "add") {
            result += stack[stack_size - 1];
            if (result > MAX_NUM) {
                cout << "OVERFLOW!!!" << endl;
                exit(0);
            }
        } else if (command == "for") {
            int num;
            cin >> num;
            stack[stack_size] = num * stack[stack_size - 1];
            if (stack[stack_size] > MAX_NUM)
                stack[stack_size] = MAX_NUM + 1;
            ++stack_size;
        } else if (command == "end") {
            --stack_size;
        } else {
            cout << "Wrong input!" << endl;
        }
    }

    cout << result << endl;

    return 0;
}