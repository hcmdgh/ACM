#include <iostream>
#include <set>
#include <vector>
using namespace std;

int N, arr[100005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d", &N) == 1) {
        for (int i = 1; i <= N; ++i) {
            scanf("%d", arr + i);
        }
        set<int> online;
        set<int> visited;
        vector<int> segments;
        bool valid = true;
        int begin = 0;
        for (int i = 1; i <= N; ++i) {
            int employee = arr[i];
            if (employee > 0) {
                if (visited.count(employee) || online.count(employee)) {
                    valid = false;
                    break;
                }
                visited.emplace(employee);
                online.emplace(employee);
            } else {
                employee = -employee;
                if (!online.count(employee)) {
                    valid = false;
                    break;
                }
                online.erase(employee);
            }
            if (online.empty()) {
                segments.emplace_back(i - begin);
                begin = i;
                visited.clear();
            }
        }
        if (!valid || !online.empty()) {
            printf("-1\n");
        } else {
            printf("%d\n", segments.size());
            printf("%d", segments[0]);
            for (int i = 1; i < segments.size(); ++i) {
                printf(" %d", segments[i]);
            }
            putchar('\n');
        }
    }

    return 0;
}