#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll A, B;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%lld%lld", &A, &B) == 2) {
        if (A < B) {
            swap(A, B);
        }
        ll width1 = A / 3;
        ll width2 = A / 2;
        ll width3 = B / 2;
        ll width4 = B;
        vector<ll> ans;
        if (width1 <= B) {
            ans.emplace_back(width1);
        }
        if (width2 * 2 <= B) {
            ans.emplace_back(width2);
        }
        if (width3 * 2 <= A) {
            ans.emplace_back(width3);
        }
        if (width4 * 3 <= A) {
            ans.emplace_back(width4);
        }
        if (ans.empty()) {
            printf("0\n");
        } else {
            printf("%lld\n", *max_element(ans.begin(), ans.end()));
        }
    }

    return 0;
}