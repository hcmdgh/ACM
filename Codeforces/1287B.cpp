#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, K;
string cards[1505];
char buffer[35];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d", &N, &K) == 2) {
        for (int i = 0; i < N; ++i) {
            scanf("%s", buffer);
            cards[i] = string(buffer);
        }
        sort(cards, cards + N);
        int cnt = 0;
        string new_str(K, 0);
        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = 0; k < K; ++k) {
                    if (cards[i][k] == cards[j][k]) {
                        new_str[k] = cards[i][k];
                    } else {
                        new_str[k] = 'S' + 'E' + 'T' - cards[i][k] - cards[j][k];
                    }
                }
                int pos = lower_bound(cards, cards + N, new_str) - cards;
                if (pos > j && pos < N && cards[pos] == new_str) {
                    ++cnt;
                }
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}