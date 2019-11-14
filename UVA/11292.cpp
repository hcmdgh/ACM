#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int diameters[20005];
int heights[20005];

const string IMPOSSIBLE = "Loowater is doomed!";

int main() {
    ios::sync_with_stdio(false);
    while ((cin >> N >> M) && (N > 0 || M > 0)) {
        for (int i = 0; i < N; ++i) {
            cin >> diameters[i];
        }
        for (int i = 0; i < M; ++i) {
            cin >> heights[i];
        }

        sort(diameters, diameters + N);
        sort(heights, heights + M);
        int money = 0;
        int cur = 0;
        bool valid = true;
        for (int i = 0; i < N; ++i) {
            int j;
            for (j = cur; j < M; ++j) {
                if (heights[j] >= diameters[i]) {
                    money += heights[j];
                    cur = j + 1;
                    break;
                }
            }
            if (j >= M) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << money << endl;
        } else {
            cout << IMPOSSIBLE << endl;
        }
    }

    return 0;
}
