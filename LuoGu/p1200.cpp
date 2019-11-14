#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string str1, str2;
    cin >> str1 >> str2;
    int num1 = 1, num2 = 1;
    for (char ch : str1) {
        num1 *= ch - 'A' + 1;
    }
    for (char ch : str2) {
        num2 *= ch - 'A' + 1;
    }
    if (num1 % 47 == num2 % 47) {
        cout << "GO" << endl;
    } else {
        cout << "STAY" << endl;
    }

    return 0;
}