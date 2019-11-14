#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int positions[100];
string S, T, P;
int lengthS;
int lengthT;
int lengthP;
int remaining[26];
int _remaining[26];
vector<int> indexesOfT[26];

bool find_pos(int index) {
    if (index >= lengthS) {
        bool valid = true;
        memcpy(_remaining, remaining, sizeof(int) * 26);
        for (int i = 0; i <= lengthS && valid; ++i) {
            int begin = (i == 0) ? 0 : positions[i - 1] + 1;
            int end = (i == lengthS) ? lengthT - 1 : positions[i] - 1;
            for (int j = begin; j <= end && valid; ++j) {
                int& r = _remaining[T[j] - 'a'];
                if (r <= 0) {
                    valid = false;
                } else {
                    --r;
                }
            }
        }
        return valid;
    }
    char ch = S[index];
    int last_pos = (index == 0) ? -1 : positions[index - 1];
    for (int i : indexesOfT[ch - 'a']) {
        if (i > last_pos) {
            positions[index] = i;
            if (find_pos(index + 1))
                return true;
        }
    }
    return false;
}

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
            for (int j = 0; j < 26; ++j) {
                indexesOfT[j].clear();
            }
            for (int j = 0; j < lengthT; ++j) {
                indexesOfT[T[j] - 'a'].emplace_back(j);
            }
            memset(remaining, 0, sizeof(int) * 26);
            for (int j = 0; j < lengthP; ++j) {
                ++remaining[P[j] - 'a'];
            }
            if (find_pos(0)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}