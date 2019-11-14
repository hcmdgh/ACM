#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N, M, K, V;
map<int, vector<int>> records;

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    while (scanf("%d%d", &N, &M) == 2) {
        records.clear();
        for (int i = 1; i <= N; ++i) {
            int val;
            scanf("%d", &val);
            auto& vec = records[val];
            vec.emplace_back(i);
        }
        for (int i = 0; i < M; ++i) {
            scanf("%d%d", &K, &V);
            auto& vec = records[V];
            if (vec.size() < K)
                printf("0\n");
            else
                printf("%d\n", vec[K-1]);
        }
    }

    return 0;
}
