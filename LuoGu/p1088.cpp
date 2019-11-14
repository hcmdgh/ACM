#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int perm[10000];
int digits[10000];
bool used[10000];

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> perm[i];

    for (int i = 0; i < N; ++i) {
        int j = 0, pos = 0;
        while (perm[i] != j + 1) {
            if (!used[j])
                ++pos;
            ++j;
        }
        digits[i] = pos;
        used[j] = true;
    }
    for (int i = 0; i < M; ++i) {
        int carry = 1;
        int index = N - 2;
        do {
            digits[index] += carry;
            carry = digits[index] / (N - index);
            digits[index] %= (N - index);
            --index;
        } while (index >= 0 && carry > 0);
        if (carry > 0) {
            cerr << "Overflow!" << endl;
            exit(1);
        }
    }

    memset(used, 0, N);
    for (int i = 0; i < N; ++i) {
        int j = -1, count = 0;
        while (count < digits[i] + 1) {
            ++j;
            if (!used[j])
                ++count;
        }
        used[j] = true;
        cout << j + 1;
        if (i < N - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}