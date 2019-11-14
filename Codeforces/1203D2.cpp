#include <iostream>
#include <string>
using namespace std;

string S, T;
int lenS, lenT;
int positions[200005];

int main() {
    ios::sync_with_stdio(false);
    cin >> S >> T;

    lenS = S.length();
    lenT = T.length();
    int cur = lenT - 1;
    for (int i = lenS - 1; i >= 0; --i) {
        if (S[i] == T[cur]) {
            positions[cur] = i;
            --cur;
        }
    }

    int max_len = positions[0];
    cur = 0;
    for (int i = 0; i < lenS; ++i) {
        char ch = S[i];
        if (ch == T[cur]) {
            positions[cur] = i;
            ++cur;
            if (cur >= lenT) {
                max_len = max(max_len, lenS - positions[lenT - 1] - 1);
                break;
            } else {
                max_len = max(max_len, positions[cur] - positions[cur-1] - 1);
            }
        }
    }

    cout << max_len << endl;

    return 0;
}
