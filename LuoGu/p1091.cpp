#include <iostream>
using namespace std;

int N;
int arr[105];
int lis[105], lis1[105], lis2[105];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
    }
    int size = 1;
    lis[0] = arr[0];
    lis1[0] = 1;
    for (int i = 1; i < N; ++i) {
        int val = arr[i];
        if (val > lis[size - 1]) {
            lis[size++] = val;
            lis1[i] = size;
        } else {
            int begin = 0, end = size - 1;
            while (begin <= end) {
                int mid = (begin + end) >> 1;
                if (lis[mid] >= val) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            }
            lis[begin] = val;
            lis1[i] = begin + 1;
        }
    }
    size = 1;
    lis[0] = arr[N - 1];
    lis2[N - 1] = 1;
    for (int i = N - 2; i >= 0; --i) {
        int val = arr[i];
        if (val > lis[size - 1]) {
            lis[size++] = val;
            lis2[i] = size;
        } else {
            int begin = 0, end = size - 1;
            while (begin <= end) {
                int mid = (begin + end) >> 1;
                if (lis[mid] >= val) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            }
            lis[begin] = val;
            lis2[i] = begin + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = max(ans, lis1[i] + lis2[i] - 1);
    }
    ans = N - ans;
    printf("%d\n", ans);

    return 0;
}
