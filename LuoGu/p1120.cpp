#include <iostream>
using namespace std;

int arr[70];
int per_len;

bool dfs()

int main() {
    int N;
    scanf("%d", &N);
    int cnt = 0;
    int max_len = 0;
    int sum_len = 0;
    while (N--) {
        int len;
        scanf("%d", &len);
        if (len > 50) {
            arr[cnt++] = len;
            max_len = max(max_len, len);
            sum_len += len;
        }
    }
    for (per_len = max_len; per_len <= sum_len; ++per_len) {

    }

    return 0;
}