#include <iostream>
#include <algorithm>
using namespace std;

int N;
int sticks[405];

int main() {
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while (Q--) {
        cin >> N;
        for (int i = 0; i < (N << 2); ++i) {
            cin >> sticks[i];
        }

        sort(sticks, sticks + (N << 2));
        bool valid = true;
        int area = -1;
        for (int i = 0; i < N; ++i) {
            int a = sticks[i << 1];
            int b = sticks[(i << 1) + 1];
            int c = sticks[(N << 2) - (i << 1) - 2];
            int d = sticks[(N << 2) - (i << 1) - 1];
            if (a != b || c != d) {
                valid = false;
                break;
            }
            if (area == -1) {
                area = a * c;
            } else if (area != a * c) {
                valid = false;
                break;
            }
        }
        if (valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
