#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int digits[3];
    char suits[3];

    cin >> digits[0] >> suits[0]
            >> digits[1] >> suits[1]
            >> digits[2] >> suits[2];

    if (suits[0] == suits[1] && suits[1] == suits[2]) {
        sort(digits, digits + 3);
        if (digits[0] == digits[1] && digits[1] == digits[2]) {
            cout << 0 << endl;
        } else if (digits[1] == digits[0] + 1 && digits[2] == digits[1] + 1) {
            cout << 0 << endl;
        } else if (digits[1] - digits[0] <= 2 || digits[2] - digits[1] <= 2) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    } else if (suits[0] != suits[1] && suits[0] != suits[2] && suits[1] != suits[2]) {
        cout << 2 << endl;
    } else {
        int id1, id2;
        if (suits[0] == suits[1]) {
            id1 = 0, id2 = 1;
        } else if (suits[0] == suits[2]) {
            id1 = 0, id2 = 2;
        } else {
            id1 = 1, id2 = 2;
        }
        if (abs(digits[id1] - digits[id2]) <= 2) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }

    return 0;
}