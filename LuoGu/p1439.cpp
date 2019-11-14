#include <iostream>
using namespace std;

int N;
int a[100005], b[100005], idx[100005];
int num2id[100005];
int len;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", a + i);
        num2id[a[i]] = i;
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", b + i);
    }
    len = 1;
    idx[0] = num2id[b[0]];
    for (int i = 1; i < N; ++i) {
        int id = num2id[b[i]];
        if (id > idx[len - 1]) {
            idx[len++] = id;
        } else {
            int begin = 0, end = len;
            while (begin <= end) {
                int mid = (begin + end) >> 1;
                if (idx[mid] > id) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            }
            idx[begin] = id;
        }
    }
    printf("%d\n", len);

    return 0;
}
