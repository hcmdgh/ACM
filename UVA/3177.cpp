#include <iostream>
using namespace std;

int N;
int r[100005];
int small[100005], big[100005];

bool judge(int num) {
    small[0] = r[0];
    big[0] = 0;
    for (int i = 1; i < N; ++i) {
        if (i & 1) {
            small[i] = min(small[0] - small[i - 1], r[i]);
            big[i] = r[i] - small[i];
        } else {
            big[i] = min(num - small[0] - big[i - 1], r[i]);
            small[i] = r[i] - big[i];
        }
    }
    return small[N - 1] == 0;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    while (scanf("%d", &N) == 1 && N > 0) {
        int begin = 2, end = 2;
        for (int i = 0; i < N; ++i) {
            scanf("%d", r + i);
            if (i > 0) {
                begin = max(begin, r[i] + r[i-1]);
            }
            end = max(end, r[i] * 3);
        }
        begin = max(begin, r[0] + r[N - 1]);
        if (N == 1) {
            printf("%d\n", r[0]);
        } else if (N & 1) {
            while (begin <= end) {
                int mid = begin + ((end - begin) >> 1);
                if (judge(mid)) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            }
            printf("%d\n", begin);
        } else {
            printf("%d\n", begin);
        }
    }

    return 0;
}
