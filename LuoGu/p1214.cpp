#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
bool flag[125005];
typedef pair<int, int> Pair;
Pair results[10005];
int results_cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;

    for (int i = 0; i <= M; ++i) {
        for (int j = 0; j <= M; ++j) {
            flag[i*i + j*j] = true;
        }
    }
    int size = M * M * 2;
    for (int i = 0; i < size; ++i) {
        if (!flag[i])
            continue;
        for (int j = 1; j <= (size - i) / (N - 1); ++j) {
            bool valid = true;
            for (int k = 0; k < N; ++k) {
                if (!flag[i + j * k]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                results[results_cnt].second = i;
                results[results_cnt].first = j;
                ++results_cnt;
            }
        }
    }

    if (results_cnt > 0) {
        sort(results, results + results_cnt);
        for (int i = 0; i < results_cnt; ++i) {
            cout << results[i].second << ' ' << results[i].first << endl;
        }
    } else {
        cout << "NONE" << endl;
    }

    return 0;
}