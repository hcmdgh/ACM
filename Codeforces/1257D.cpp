#include <iostream>
#include <algorithm>
using namespace std;

int T, N, M;
int monsters[200005];
struct Hero {
    int p, s;

    bool operator<(const Hero& other) const {
        return p > other.p;
    }
} heroes[200005];
int hero_next[200005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", monsters + i);
        }
        scanf("%d", &M);
        for (int i = 0; i < M; ++i) {
            scanf("%d%d", &heroes[i].p, &heroes[i].s);
        }
        sort(heroes, heroes + M);
        int head = 0, tail = 0;
        hero_next[0] = -1;
        for (int i = 1; i < M; ++i) {
            if (heroes[i].s > heroes[tail].s) {
                hero_next[tail] = i;
                tail = i;
                hero_next[i] = -1;
            }
        }

        int monster = 0, days = 0;
        while (monster < N) {
            int max_power = -1;
            int cnt = 0;
            int hero = head;
            int last_monster = monster;
            while (monster < N) {
                max_power = max(max_power, monsters[monster]);
                ++cnt;
                if (max_power > heroes[hero].p)
                    break;
                if (cnt > heroes[hero].s) {
                    hero = hero_next[hero];
                    if (hero == -1 || heroes[hero].p < max_power) {
                        break;
                    }
                }
                ++monster;
            }
            ++days;
            if (last_monster == monster) {
                days = -1;
                break;
            }
        }
        printf("%d\n", days);
    }

    return 0;
}