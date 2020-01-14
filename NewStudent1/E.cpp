#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int wt[100005];
int hm[100005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", wt + i);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d", hm + i);
    }
    sort(wt, wt + N);
    sort(hm, hm + M);
    int cur = 0;
    int sum = 0;
    for (int i = 0; i < M; ++i) {
        if (cur >= N) {
            sum += hm[i];
        } else if (hm[i] >= wt[cur]) {
            sum += hm[i] - wt[cur];
            ++cur;
        }
    }
    printf("%d\n", sum);

    return 0;
}