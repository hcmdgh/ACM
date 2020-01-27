#include <iostream>
#include <climits>
using namespace std;

int N, R, X, Y, V;
const int MAXN = 5001;
int graph[5005][5005];
int prefix_sum[5005][5005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &N, &R);
//    R -= 2;
    if (R <= 0) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d%d%d", &X, &Y, &V);
        graph[X + 1][Y + 1] += V;
    }
    for (int i = 1; i <= MAXN; ++i) {
        for (int j = 1; j <= MAXN; ++j) {
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + graph[i][j];
        }
    }
    int max_sum = INT_MIN;
    for (int i = 1; i <= MAXN - R + 1; ++i) {
        for (int j = 1; j <= MAXN - R + 1; ++j) {
            int ii = i + R - 1;
            int jj = j + R - 1;
            int sum = prefix_sum[ii][jj] - prefix_sum[i - 1][jj] - prefix_sum[ii][j - 1] + prefix_sum[i - 1][j - 1];
            max_sum = max(max_sum, sum);
        }
    }
    printf("%d\n", max_sum);

    return 0;
}