#include <iostream>
using namespace std;

int N;
char necklace[1200];

int count(int pos, int step) {
    int cnt = 0;
    char color = 'w';
    while (pos >= 0 && pos < N * 3) {
        char _color = necklace[pos];
        if (color == 'w') {
            color = _color;
        } else if (_color != 'w' && color != _color) {
            return cnt;
        }
        ++cnt;
        pos += step;
    }
    return cnt;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%s", &N, necklace);
    for (int i = 1; i <= 2; ++i) {
        for (int j = 0; j < N; ++j) {
            necklace[i * N + j] = necklace[j];
        }
    }
//    cout << necklace << endl;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int left_begin = N + i;
        int right_begin = N + i + 1;
        int left_cnt = count(left_begin, -1);
        int right_cnt = count(right_begin, 1);
//        printf("%d %d %d %d\n", left_begin, right_begin, left_cnt, right_cnt);
        ans = max(ans, min(left_cnt + right_cnt, N));
    }
    printf("%d\n", ans);

    return 0;
}