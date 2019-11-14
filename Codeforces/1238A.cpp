#include <iostream>
using namespace std;

int T;
typedef long long ll;
ll X, Y;

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &X, &Y);
        ll temp = X - Y;
        if (temp > 1) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}
