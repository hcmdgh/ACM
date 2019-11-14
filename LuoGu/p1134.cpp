#include <iostream>
using namespace std;

typedef long long ll;
int N;

int main() {
    while (scanf("%d", &N) == 1) {
        ll digit = 1;
        for (int i = 2; i <= N; ++i) {
            digit *= i;
            while (digit % 10 == 0) {
                digit /= 10;
            }
            digit %= 1000000000;
        }
        printf("%d\n", digit % 10);
    }

    return 0;
}
