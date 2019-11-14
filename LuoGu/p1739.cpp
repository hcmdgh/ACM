#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    char input;
    int left_count = 0;
    while ((cin >> input) && input != '@') {
        if (input == '(') {
            ++left_count;
        } else if (input == ')') {
            if (left_count <= 0) {
                cout << "NO" << endl;
                return 0;
            }
            --left_count;
        }
    }
    if (left_count == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}