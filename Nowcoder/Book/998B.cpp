#include <iostream>
using namespace std;

int N, M;
int arr[100];

void dfs(int begin, int cnt) {
    if (cnt > M) {
        printf("%d", arr[1]);
        for (int i = 2; i <= M; ++i) {
            printf(" %d", arr[i]);
        }
        putchar('\n');
    } else {
        for (int i = begin; i <= N; ++i) {
            arr[cnt] = i;
            dfs(i + 1, cnt + 1);
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    dfs(1, 1);

    return 0;
}