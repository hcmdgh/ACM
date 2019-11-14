#include <iostream>
#include <map>
using namespace std;

int T, N;
int arr[200005];
int _left[200005];
int _right[200005];
map<int, int> map_pos;
const int INF = 1e7;

int find_unique(int begin, int end) {
    int half_len = (end - begin + 2) >> 1;
    for (int i = 0; i < half_len; ++i) {
        int j = begin + i;
        if (_left[j] < begin && _right[j] > end)
            return j;
        j = end - i;
        if (_left[j] < begin && _right[j] > end)
            return j;
    }
    return -1;
}

bool judge(int begin, int end) {
    if (begin >= end)
        return true;
    int pos = find_unique(begin, end);
    if (pos == -1)
        return false;
    return judge(begin, pos - 1) && judge(pos + 1, end);
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // DEBUG
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            scanf("%d", arr + i);
        }
        map_pos.clear();
        for (int i = 1; i <= N; ++i) {
            if (map_pos.count(arr[i])) {
                _left[i] = map_pos[arr[i]];
            } else {
                _left[i] = -1;
            }
            map_pos[arr[i]] = i;
        }
        map_pos.clear();
        for (int i = N; i >= 1; --i) {
            if (map_pos.count(arr[i])) {
                _right[i] = map_pos[arr[i]];
            } else {
                _right[i] = INF;
            }
            map_pos[arr[i]] = i;
        }
        bool res = judge(1, N);
        if (res) {
            printf("non-boring\n");
        } else {
            printf("boring\n");
        }
    }

    return 0;
}
