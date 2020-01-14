#include <iostream>
#include <set>
using namespace std;

typedef long long ll;

int main() {
    set<int> ks;
    for (ll a = -500; a <= 500; ++a) {
        for (ll b = -500; b <= 500; ++b) {
            for (ll c = -500; c <= 500; ++c) {
                ll k = a*a*a + b*b*b + c*c*c;
                if (k >= 0 && k <= 200) {
                    ks.emplace(k);
                }
            }
        }
    }
    printf("%d\n", ks.size());

    ks.clear();
    for (ll a = -1000; a <= 1000; ++a) {
        for (ll b = -1000; b <= 1000; ++b) {
            for (ll c = -1000; c <= 1000; ++c) {
                ll k = a*a*a + b*b*b + c*c*c;
                if (k >= 0 && k <= 200) {
                    ks.emplace(k);
                }
            }
        }
    }
    printf("%d\n", ks.size());

    return 0;
}