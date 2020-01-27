#include <iostream>
#include <climits>
#include <vector>
#include <map>
using namespace std;

int N, M;
vector<vector<int>> matrix;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d", &N, &M) == 2) {
        matrix = vector<vector<int>>(N, vector<int>(M));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                scanf("%d", &matrix[i][j]);
            }
        }
        vector<int> cnt(N);
        int ans = 0;
        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                int num = matrix[i][j];
                int mi = num - j - 1;
                if (mi % M == 0) {
                    int ii = mi / M;
                    if (ii >= 0 && ii <= N - 1) {
                        cnt[i] = (i - ii + N) % N;
                    } else {
                        cnt[i] = -1;
                    }
                } else {
                    cnt[i] = -1;
                }
            }
            map<int, int> _map;
            for (int i = 0; i < N; ++i) {
                if (cnt[i] >= 0) {
                    ++_map[cnt[i]];
                }
            }
            int optimum = N;
            for (auto item : _map) {
                optimum = min(optimum, item.first + N - item.second);
            }
            ans += optimum;
        }
        printf("%d\n", ans);
    }

    return 0;
}