#include <iostream>
#include <algorithm>
using namespace std;

int positions[100000];
int A, B;

bool judge(int distance) {
    int count = 1;
    int pos = positions[0];
    for (int i = 1; i < A; ++i) {
        if (positions[i] - pos >= distance) {
            ++count;
            pos = positions[i];
        }
    }
    return count >= B;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> A >> B;
    for (int i = 0; i < A; ++i) {
        cin >> positions[i];
    }

    sort(positions, positions + A);
    int left = 1, right = positions[A - 1] - positions[0];
    while (left <= right) {
        int mid = (left + right) / 2;
        if (!judge(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << right << endl;

    return 0;
}