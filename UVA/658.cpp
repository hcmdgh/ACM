#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
struct Patch {
    int time;
    char require[25], effect[25];

    void read() {
        scanf("%d%s%s", &time, require, effect);
    }

    int move(int state) {
        for (int i = 0; i < N; ++i) {
            if (require[i] == '+' && !(state & (1<<i)))
                return -1;
            if (require[i] == '-' && (state & (1<<i)))
                return -1;
        }
        int new_state = state;
        for (int i = 0; i < N; ++i) {
            if (effect[i] == '+')
                new_state |= (1 << i);
            else if (effect[i] == '-')
                new_state &= ~(1 << i);
        }
        return new_state;
    }
} patches[105];

struct Node {
    int bugs, dis;

    Node(int bugs, int dis) : bugs(bugs), dis(dis) {}

    bool operator<(const Node& other) const {
        return dis > other.dis;
    }
};
const int MAXN = (1<<20)+5;
bool visited[MAXN];
int dis[MAXN];
const int INF = 0x3F3F3F3F;

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    int kase = 0;
    while (scanf("%d%d", &N, &M) == 2 && N) {
        printf("Product %d\n", ++kase);
        for (int i = 0; i < M; ++i) {
            patches[i].read();
        }
        memset(visited, 0, sizeof(visited));
        priority_queue<Node> pq;
        pq.emplace(Node((1 << N) - 1, 0));
        memset(dis, 0x3F, sizeof(dis));
        dis[(1 << N) - 1] = 0;
        while (!pq.empty()) {
            Node top = pq.top();
            pq.pop();
            if (!visited[top.bugs]) {
                visited[top.bugs] = true;
                for (int i = 0; i < M; ++i) {
                    int new_state = patches[i].move(top.bugs);
                    if (new_state != -1 && dis[top.bugs] + patches[i].time < dis[new_state]) {
                        dis[new_state] = dis[top.bugs] + patches[i].time;
                        if (!visited[new_state])
                            pq.emplace(Node(new_state, dis[new_state]));
                    }
                }
            }
        }
        if (dis[0] < INF) {
            printf("Fastest sequence takes %d seconds.\n\n", dis[0]);
        } else {
            printf("Bugs cannot be fixed.\n\n");
        }
    }

    return 0;
}
