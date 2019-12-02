#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int arr[25];
int choices[25];
int ans = 0;
bool visited[2005];

void dfs(int pos, int begin) {
    if (pos >= M) {
        memset(visited, 0, sizeof(visited));
        visited[choices[0]] = true;
        for (int i = 1; i < M; ++i) {
            for (int j = 2000 - choices[i]; j >= 1; --j) {
                if (visited[j])
                    visited[j + choices[i]] = true;
            }
            visited[choices[i]] = true;
        }
        int cnt = 0;
        for (int i = 1; i <= 2000; ++i) {
            cnt += visited[i];
        }
        ans = max(ans, cnt);
    } else {
        int last_choice = -1;
        for (int i = begin; i <= N - (M - pos); ++i) {
            if (last_choice == -1 || arr[i] != last_choice) {
                choices[pos] = arr[i];
                dfs(pos + 1, i + 1);
            }
            last_choice = arr[i];
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &N, &M);
    M = N - M;
    for (int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
    }
    sort(arr, arr + N);
    dfs(0, 0);
    printf("%d\n", ans);

    return 0;
}