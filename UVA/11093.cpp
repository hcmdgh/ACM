#include <iostream>
using namespace std;

int T, N;
int store[100005];
int need[100005];

int go(int start) {
    int pos = start;
    int petrol = 0;
    do {
        petrol += store[pos];
        petrol -= need[pos];
        pos = pos % N + 1;
    } while (petrol >= 0 && pos != start);
    if (petrol < 0) {
        return pos;
    } else {
        return -1;
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            scanf("%d", store + i);
        }
        for (int i = 1; i <= N; ++i) {
            scanf("%d", need + i);
        }
        int ans = 0;
        int pos = 1;
        while (true) {
            int end = go(pos);
            if (end == -1) {
                ans = pos;
                break;
            } else if (end <= pos) {
                break;
            }
            pos = end;
        }
        printf("Case %d: ", kase);
        if (ans == 0) {
            printf("Not possible\n");
        } else {
            printf("Possible from station %d\n", ans);
        }
    }

    return 0;
}
