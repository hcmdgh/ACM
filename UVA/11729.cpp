#include <iostream>
#include <algorithm>
using namespace std;

int N;
typedef pair<int, int> Pair;
Pair soldiers[1005];

bool cmp(const Pair& pair1, const Pair& pair2) {
    return pair1.second > pair2.second;
}

int main() {
    ios::sync_with_stdio(false);
    int Q = 0;
    while ((cin >> N) && N > 0) {
        ++Q;
        for (int i = 0; i < N; ++i) {
            cin >> soldiers[i].first >> soldiers[i].second;
        }
        sort(soldiers, soldiers + N, cmp);
        int begin_time = 0;
        int end_time = 0;
        for (int i = 0; i < N; ++i) {
            begin_time += soldiers[i].first;
            end_time = max(end_time, begin_time + soldiers[i].second);
        }
        cout << "Case " << Q << ": " << end_time << endl;
    }

    return 0;
}
