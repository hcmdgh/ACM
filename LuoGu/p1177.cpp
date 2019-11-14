#include <iostream>
using namespace std;

int N;
int arr[100005];

void heap_sort() {
    for (int i = 1; i < N; ++i) {
        int cur = i, fa;
        while (cur > 0 && arr[cur] > arr[fa = (cur-1)>>1]) {
            swap(arr[cur], arr[fa]);
            cur = fa;
        }
    }
    for (int i = N - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        int cur = 0;
        while (true) {
            int son = (cur << 1) ^ 1;
            if (son + 1 < i && arr[son + 1] > arr[son])
                ++son;
            if (son < i && arr[cur] < arr[son]) {
                swap(arr[cur], arr[son]);
                cur = son;
            } else {
                break;
            }
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
    }

    heap_sort();

    printf("%d", arr[0]);
    for (int i = 1; i < N; ++i) {
        printf(" %d", arr[i]);
    }
    putchar('\n');

    return 0;
}