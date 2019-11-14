#include <iostream>
#include <queue>
using namespace std;

char buffer[10];
struct Query {
    int period, id, time;

    bool operator<(const Query& other) const {
        return time > other.time || (time == other.time && id > other.id);
    }
};
int K;
priority_queue<Query> pq;

int main() {
    while (scanf("%s", buffer) == 1 && buffer[0] != '#') {
        Query query;
        scanf("%d%d", &query.id, &query.period);
        query.time = query.period;
        pq.emplace(query);
    }
    scanf("%d", &K);
    for (int i = 0; i < K; ++i) {
        Query top = pq.top();
        pq.pop();
        printf("%d\n", top.id);
        top.time += top.period;
        pq.emplace(top);
    }

    return 0;
}
