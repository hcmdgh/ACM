#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;

int main() {
    while (scanf("%d", &N) == 1 && N > 0) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < N; ++i) {
            int val;
            scanf("%d", &val);
            pq.emplace(val);
        }
        int cost = 0;
        while (pq.size() >= 2) {
            int val1 = pq.top();
            pq.pop();
            int val2 = pq.top();
            pq.pop();
            int sum = val1 + val2;
            cost += sum;
            pq.emplace(sum);
        }
        printf("%d\n", cost);
    }

    return 0;
}
