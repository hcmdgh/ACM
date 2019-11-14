#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int T, N, S;
int arr[300010];
bool valid[300010];
map<int, int> window_elems;

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &S, &N);
        memset(valid, 0, S + N + 5);
        window_elems.clear();
        for (int i = 1; i <= S - 1; ++i) {
            arr[i] = -i;
        }
        for (int i = S; i <= N + S - 1; ++i) {
            scanf("%d", arr + i);
        }
        for (int i = N + S; i <= N + S + S - 2; ++i) {
            arr[i] = N - i;
        }
        for (int i = 1; i <= S; ++i) {
            ++window_elems[arr[i]];
        }
        valid[1] = true;
        for (int i = 2; i <= N + S - 1; ++i) {
            --window_elems[arr[i-1]];
            if (window_elems[arr[i-1]] <= 0)
                window_elems.erase(arr[i-1]);
            ++window_elems[arr[i+S-1]];
            valid[i] = window_elems.size() == S;
        }
        int ans = 0;
        for (int i = 1; i <= S; ++i) {
            bool ok = true;
            for (int j = i; j <= N + S - 1; j += S) {
                if (!valid[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ++ans;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
