#include <iostream>
using namespace std;

#define MOD(x) (((x) % N + N) % N)

int N, arr[25];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; ++i) {
            scanf("%d", arr + i);
        }
        int step1 = 0, step2 = 0;
        for (int i = 0; i < N; ++i) {
            if (arr[i]) {
                ++step1;
            } else {
                break;
            }
        }
        for (int i = N - 1; i >= 0; --i) {
            if (arr[i]) {
                ++step2;
            } else {
                break;
            }
        }
        if ((step1 & 1) || (step2 & 1)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}