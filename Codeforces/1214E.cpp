#include <cstdio>
#include <algorithm>
using namespace std;

int N;
struct Distance {
    int d, src;

    bool operator<(const Distance& other) const {
        return d > other.d;
    }
} d[100005];
int chain[200005];
int _chain[200005];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &d[i].d);
        d[i].src = i * 2 + 1;
    }

    sort(d, d + N);
    for (int i = 0; i < N - 1; ++i) {
        printf("%d %d\n", d[i].src, d[i+1].src);
    }
    for (int i = 0; i < N; ++i) {
        chain[i] = d[i].src;
        _chain[d[i].src] = i;
    }
    int chain_size = N;
    for (int i = 0; i < N; ++i) {
        int dis = d[i].d;
        int src = d[i].src;
        int dest = src + 1;
        int id = _chain[src];
        int _dis = dis - 1;
        int _src;
        if (id - _dis >= 0) {
            _src = chain[id - _dis];
        } else if (id + _dis < chain_size - 1) {
            _src = chain[id + _dis];
        } else {
            _src = chain[chain_size - 1];
            chain[chain_size] = dest;
            ++chain_size;
        }
        printf("%d %d\n", _src, dest);
    }

    return 0;
}
