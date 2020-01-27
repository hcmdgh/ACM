#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;

int Q, X;
int arr[400005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d", &Q, &X) == 2) {
        for (int i = 0; i < Q; ++i) {
            scanf("%d", arr + i);
            arr[i] %= X;
        }
        map<int, queue<int>> unused;
        set<int> _unused;
        for (int i = 0; i <= Q; ++i) {
            unused[i % X].emplace(i);
            _unused.emplace(i);
        }
        for (int i = 0; i < Q; ++i) {
            auto iter = unused.find(arr[i]);
            if (iter != unused.end()) {
                int num = iter->second.front();
                _unused.erase(num);
                iter->second.pop();
                if (iter->second.empty()) {
                    unused.erase(iter);
                }
            }
            printf("%d\n", *_unused.begin());
        }
    }

    return 0;
}