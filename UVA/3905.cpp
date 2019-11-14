#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int W, H, N;
struct Meteor {
    int x, y, vx, vy;
    int begin_time, end_time;

    void _calcTime(int _x, int _vx, int bound) {
        if (_vx == 0) {
            if (_x <= 0 || _x >= bound) {
                begin_time = -1, end_time = -2;
            }
        } else if (_vx > 0) {
            begin_time = max(begin_time, (-_x) / _vx);
            end_time = min(end_time, (bound-_x) / _vx);
        } else {
            begin_time = max(begin_time, (bound-_x) / _vx);
            end_time = min(end_time, (-_x) / _vx);
        }
    }

    void calcTime() {
        begin_time = -1;
        end_time = INT_MAX;
        _calcTime(x, vx, W);
        _calcTime(y, vy, H);
    }
} meteors[100005];

struct Event {
    int pos;
    bool type;  // true:左端点 false:右端点

    bool operator<(const Event& other) const {
        return pos < other.pos || (pos == other.pos && !type && other.type);
    }
} events[200005];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &W, &H, &N);
        W *= 2520;
        H *= 2520;
        int events_cnt = 0;
        for (int i = 0; i < N; ++i) {
            int x, y;
            scanf("%d%d%d%d", &x, &y, &meteors[i].vx, &meteors[i].vy);
            meteors[i].x = x * 2520;
            meteors[i].y = y * 2520;
            meteors[i].calcTime();
            if (meteors[i].begin_time < meteors[i].end_time) {
                events[events_cnt].pos = meteors[i].begin_time;
                events[events_cnt].type = true;
                ++events_cnt;
                events[events_cnt].pos = meteors[i].end_time;
                events[events_cnt].type = false;
                ++events_cnt;
            }
        }
        sort(events, events + events_cnt);
        int ans = 0, cnt = 0;
        for (int i = 0; i < events_cnt; ++i) {
            if (events[i].type) {
                ++cnt;
                ans = max(ans, cnt);
            } else {
                --cnt;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
