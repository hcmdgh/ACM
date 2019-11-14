#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int arr[20];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    int Q = 0;
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; ++i) {
            scanf("%d", arr + i);
        }
        long long max_product = 0;
        long long product;
        for (int i = 0; i < N; ++i) {
            product = 1;
            for (int j = i; j < N; ++j) {
                product *= arr[j];
                max_product = max(max_product, product);
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", ++Q, max_product);
    }

    return 0;
}
