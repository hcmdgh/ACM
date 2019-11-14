#include <iostream>
#include <string>
using namespace std;

const char MATCH[] = "2223334445556667 77888999 ";

int main() {
    ios::sync_with_stdio(false);
    string digits, alphas;
    cin >> digits;
    int digits_length = digits.length();
    bool found = false;
    while ((cin >> alphas) && alphas != "shit") {
        int alphas_length = alphas.length();
        if (alphas_length == digits_length) {
            bool valid = true;
            for (int i = 0; i < alphas_length; ++i) {
                char ch = alphas[i];
                if (MATCH[ch - 'A'] != digits[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                found = true;
                cout << alphas << endl;
            }
        }
    }
    if (!found)
        cout << "NONE" << endl;

    return 0;
}