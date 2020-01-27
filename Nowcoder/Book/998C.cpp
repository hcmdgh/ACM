#include <iostream>
using namespace std;

int N;
int arr[15];
bool used[15];

void dfs(int pos) {
    if (pos >= N) {
        printf("%d", arr[0]);
        for (int i = 1; i < N; ++i) {
            printf(" %d", arr[i]);
        }
        putchar('\n');
    } else {
        for (int i = 1; i <= N; ++i) {
            if (!used[i]) {
                used[i] = true;
                arr[pos] = i;
                dfs(pos + 1);
                used[i] = false;
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    dfs(0);

    return 0;
}