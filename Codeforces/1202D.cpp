#include <iostream>
using namespace std;

typedef long long ll;
char str[100005];
typedef pair<int, int> Three;
Three threes[100000];
int threes_cnt = 0;

void init() {
    ll i = 2;
    while (true) {
        ll c = i * (i - 1) / 2;
        if (c > 1000000000)
            break;
        threes[threes_cnt].first = i;
        threes[threes_cnt].second = c;
        ++threes_cnt;
        ++i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    init();
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        if (N <= 10) {
            for (int i = 0; i < N; ++i) {
                str[i] = '1';
            }
            str[N] = str[N + 1] = '3';
            str[N + 2] = '7';
            str[N + 3] = 0;
            cout << str << endl;
        } else {
            int left = 0, right = threes_cnt - 1;
            while (left <= right) {
                int mid = (left + right) >> 1;
                if (threes[mid].second < N) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            int cnt = threes[right].first;
            int remaining = N - threes[right].second;
            str[0] = '1';
            for (int i = 0; i < cnt - 2; ++i) {
                str[i + 1] = '3';
            }
            for (int i = 0; i < remaining; ++i) {
                str[cnt - 1 + i] = '1';
            }
            str[cnt + remaining - 1] = str[cnt + remaining] = '3';
            str[cnt + remaining + 1] = '7';
            str[cnt + remaining + 2] = 0;
            cout << str << endl;
        }
    }

    return 0;
}