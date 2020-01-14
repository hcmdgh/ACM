#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int N, M;
int wt[100005];
map<int, int, greater<int>> hm;
bool used[100005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", wt + i);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int val;
        scanf("%d", &val);
        ++hm[val];
    }
    sort(wt, wt + N, greater<int>());
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int attack = wt[i];
        auto iter = hm.begin();
        if (iter == hm.end()) {
            break;
        }
        if (attack >= iter->first) {
            sum += attack - iter->first;
            used[i] = true;
            --iter->second;
            if (iter->second <= 0) {
                hm.erase(iter);
            }
        }
    }
    if (hm.empty()) {
        printf("%d\n", sum);
    } else {

    }

    return 0;
}