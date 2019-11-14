#include <cstdio>
using namespace std;

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        int num = N;
        int cnt = 0;
        while (num > 0) {
            num /= 2;
            ++cnt;
        }
        printf("%d\n", cnt);
    }

    return 0;
}
