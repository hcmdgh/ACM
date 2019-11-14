#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

string S, T, P;
int lengthS;
int lengthT;
int lengthP;
int remaining[26];

int main() {
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> S >> T >> P;
        lengthS = S.length();
        lengthT = T.length();
        lengthP = P.length();
        if (lengthS > lengthT) {
            cout << "NO" << endl;
        } else {
            memset(remaining, 0, sizeof(int) * 26);
            for (int j = 0; j < lengthP; ++j) {
                ++remaining[P[j] - 'a'];
            }
            int index = 0;
            bool valid = true;
            for (int j = 0; j < lengthT; ++j) {
                if (index < lengthS && T[j] == S[index]) {
                    ++index;
                } else {
                    int& r = remaining[T[j] - 'a'];
                    if (r <= 0) {
                        valid = false;
                        break;
                    }
                    --r;
                }
            }
            if (valid && index == lengthS) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}