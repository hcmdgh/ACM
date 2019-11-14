#include <iostream>
using namespace std;

int N;
int _next[100005];
int dfn[100005];
int cycle_size[100005];
int cycle_time[100005];
int color[100005];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", _next + i);
    }
    for (int cow = 1; cow <= N; ++cow) {
        int step = 0;
        int pos = cow;
        while (true) {
            int col = color[pos];
            if (col == 0) {
                color[pos] = cow;
                dfn[pos] = step;
            } else if (col == cow) {
                cycle_size[cow] = step - dfn[pos];
                cycle_time[cow] = dfn[pos];
                printf("%d\n", step);
                break;
            } else {
                cycle_size[cow] = cycle_size[col];
                if (dfn[pos] > cycle_time[col]) {
                    cycle_time[cow] = step;
                } else {
                    cycle_time[cow] = step + cycle_time[col] - dfn[pos];
                }
                printf("%d\n", cycle_time[cow] + cycle_size[cow]);
                break;
            }
            ++step;
            pos = _next[pos];
        }
    }

    return 0;
}
