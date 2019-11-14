#include <iostream>
using namespace std;

int T;
int arr[205];
typedef long long ll;
const int _MOD = 10001;
#define MOD(x) ((((x) % _MOD) + _MOD) % _MOD)

void exgcd(int a, int b, int& d, int& x, int& y) {
    if (b == 0) {
        d = a, x = 1, y = 0;
    } else {
        exgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        scanf("%d", &arr[i*2+1]);
    }
    int x1 = arr[1], x3 = arr[3];
    for (int a = 0; a < _MOD; ++a) {
        int _right = MOD(x3 - a * a * x1);
        int d, x, y;
        exgcd(a + 1, _MOD, d, x, y);
        if (_right % d == 0) {
            int times = _right / d;
            x *= times, y *= times;
            int b = MOD(x);
            bool valid = true;
            for (int i = 2; i <= T * 2; ++i) {
                if (i & 1) {
                    if (arr[i] != MOD(a * arr[i-1] + b)) {
                        valid = false;
                        break;
                    }
                } else {
                    arr[i] = MOD(a * arr[i-1] + b);
                }
            }
            if (valid) {
                for (int i = 0; i < T; ++i) {
                    printf("%d\n", arr[i*2+2]);
                }
                break;
            }
        }
    }

    return 0;
}
