#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int V;
int required[25];
int G;
int food[15][25];
int choose[16];
int vitamin[25];
int ans[15];

int main() {
    ios::sync_with_stdio(false);
    cin >> V;
    for (int i = 0; i < V; ++i) {
        cin >> required[i];
    }
    cin >> G;
    for (int i = 0; i < G; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> food[i][j];
        }
    }

    int min_cnt = INT_MAX;
    while (true) {
        ++choose[0];
        for (int i = 0; i < G; ++i) {
            if (choose[i] >= 2) {
                ++choose[i + 1];
                choose[i] &= 1;
            }
        }
        if (choose[G])
            break;
        memset(vitamin, 0, sizeof(int) * V);
        int cnt = 0;
        for (int i = 0; i < G; ++i) {
            if (choose[i]) {
                ++cnt;
                for (int j = 0; j < V; ++j) {
                    vitamin[j] += food[i][j];
                }
            }
        }
        if (cnt < min_cnt) {
            bool valid = true;
            for (int i = 0; i < V; ++i) {
                if (vitamin[i] < required[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                min_cnt = cnt;
                for (int i = 0; i < G; ++i) {
                    if (choose[i]) {
                        ans[min_cnt - cnt] = i + 1;
                        --cnt;
                    }
                }
            }
        }
    }

    cout << min_cnt << ' ';
    for (int i = 0; i < min_cnt; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}
