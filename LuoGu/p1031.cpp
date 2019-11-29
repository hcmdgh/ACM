#include <iostream>
using namespace std;

int N, arr[105];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
        sum += arr[i];
    }
    int per = sum / N;
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (arr[i] != per) {
            arr[i + 1] += arr[i] - per;
            ++cnt;
        }
    }
    printf("%d\n", cnt);

    return 0;
}