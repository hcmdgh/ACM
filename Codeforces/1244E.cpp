#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
int N;
ll K;
map<int, int> nums;

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    while (scanf("%d%I64d", &N, &K) == 2) {
        nums.clear();
        for (int i = 0; i < N; ++i) {
            int val;
            scanf("%d", &val);
            ++nums[val];
        }
        while (nums.size() > 1) {
            auto iter = nums.begin();
            ll low = iter->first;
            ++iter;
            ll _low = iter->first;
            auto iter2 = nums.rbegin();
            ll high = iter2->first;
            ++iter2;
            ll _high = iter2->first;
            ll low_cnt = nums[low];
            ll high_cnt = nums[high];

            if (low_cnt < high_cnt) {
                ll step = min(_low - low, K / low_cnt);
                if (step == 0)
                    break;
                nums[low + step] += low_cnt;
                K -= step * low_cnt;
                nums.erase(low);
            } else {
                ll step = min(high - _high, K / high_cnt);
                if (step == 0)
                    break;
                nums[high - step] += high_cnt;
                K -= step * high_cnt;
                nums.erase(high);
            }
        }
        int low = nums.begin()->first;
        int high = nums.rbegin()->first;
        printf("%d\n", abs(low - high));
    }

    return 0;
}
