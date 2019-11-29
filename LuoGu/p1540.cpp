#include <iostream>
#include <queue>
#include <set>
using namespace std;

int M, N;
queue<int> memory_queue;
set<int> memory_set;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &M, &N);
    int cnt = 0;
    while (N--) {
        int word;
        scanf("%d", &word);
        if (!memory_set.count(word)) {
            memory_set.emplace(word);
            ++cnt;
            if (memory_queue.size() >= M) {
                int remove = memory_queue.front();
                memory_set.erase(remove);
                memory_queue.pop();
            }
            memory_queue.emplace(word);
        }
    }
    printf("%d\n", cnt);

    return 0;
}