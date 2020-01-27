#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> arr[5];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &M);
        int sum = 0;
        for (int j = 0; j < M; ++j) {
            int val;
            scanf("%d", &val);
            sum += val;
        }
        arr[M].emplace_back(sum);
    }
    for (int i = 1; i <= 3; ++i) {
        sort(arr[i].begin(), arr[i].end(), greater<int>());
    }
    int ans = 0;
    for (int i = 0; i <= 5; ++i) {
        for (int j = 0; j <= 2; ++j) {
            for (int k = 0; k <= 1; ++k) {
                if (i + j * 2 + k * 3 <= 5) {
                    int sum = 0;
                    for (int temp = 0; temp < min(i, int(arr[1].size())); ++temp) {
                        sum += arr[1][temp];
                    }
                    for (int temp = 0; temp < min(j, int(arr[2].size())); ++temp) {
                        sum += arr[2][temp];
                    }
                    for (int temp = 0; temp < min(k, int(arr[3].size())); ++temp) {
                        sum += arr[3][temp];
                    }
//                    if (sum > ans) {
//                        printf("%d %d %d\n", i, j, k);
                        ans = max(ans, sum);
//                    }
                }
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}