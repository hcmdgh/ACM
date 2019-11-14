#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int N, K;
int digits[20];
typedef long long ll;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &K);
        set<int> nums;
        nums.emplace(K);
        int num = K;
        while (true) {
            ll temp = (ll)num * num;
            int cnt = 0;
            while (temp > 0) {
                digits[cnt] = temp % 10;
                ++cnt;
                temp /= 10;
            }
            num = 0;
            for (int i = cnt - 1; i >= cnt - N; --i) {
                num = num * 10 + digits[i];
            }
            if (nums.count(num))
                break;
            nums.emplace(num);
        }
        auto iter = nums.rbegin();
        printf("%d\n", *iter);
    }

    return 0;
}
