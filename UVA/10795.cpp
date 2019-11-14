#include <cstdio>
using namespace std;

typedef long long ll;
int N;
int src[65];
int dest[65];

ll move_disk(int id, int dest_pillar) {
    int src_pillar = src[id];
    if (src_pillar == dest_pillar) {
        return 0;
    } else {
        ll cnt = 0;
        bool quick_move = true;
        for (int i = 0; i <= id - 1; ++i) {
            if (src[i] != src_pillar) {
                quick_move = false;
                break;
            }
        }
        if (quick_move) {
            cnt += (1LL << id) - 1;
            for (int i = 0; i <= id - 1; ++i) {
                src[i] = 6 - src_pillar - dest_pillar;
            }
        } else {
            for (int i = id - 1; i >= 0; --i) {
                cnt += move_disk(i, 6 - src_pillar - dest_pillar);
            }
        }
        src[id] = dest_pillar;
        return cnt + 1;
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    int Q = 0;
    while (scanf("%d", &N) == 1 && N > 0) {
        for (int i = 0; i < N; ++i) {
            scanf("%d", src + i);
        }
        for (int i = 0; i < N; ++i) {
            scanf("%d", dest + i);
        }

        ll cnt = 0;
        for (int i = N - 1; i >= 0; --i) {
            cnt += move_disk(i, dest[i]);
        }
        printf("Case %d: %lld\n", ++Q, cnt);
    }


    return 0;
}
