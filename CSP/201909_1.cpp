#include <iostream>
using namespace std;

int N, M;

int main() {
    scanf("%d%d", &N, &M);
    int cnt = 0, max_removed = -1, idx;
    for (int i = 0; i < N; ++i) {
        int removed = 0;
        for (int j = 0; j < M + 1; ++j) {
            int num;
            scanf("%d", &num);
            cnt += num;
            if (j > 0) {
                removed += -num;
            }
        }
        if (removed > max_removed) {
            max_removed = removed;
            idx = i + 1;
        }
    }
    printf("%d %d %d\n", cnt, idx, max_removed);

    return 0;
}