#include <iostream>
using namespace std;

int N;
int pillars[200000];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    int dest_pos = -1;
    for (int i = 0; i < N; ++i) {
        cin >> pillars[i];
        if (pillars[i] == N) {
            dest_pos = i;
        }
    }

    int left = dest_pos - 1, right = dest_pos + 1;
    bool valid = true;
    for (int i = N - 1; i >= 1; --i) {
        if (left >= 0 && pillars[left] == i) {
            --left;
        } else if (right < N && pillars[right] == i) {
            ++right;
        } else {
            valid = false;
            break;
        }
    }

    if (valid) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}