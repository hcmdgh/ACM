#include <iostream>
#include <cstring>
using namespace std;

int N, M;
bool used[300001];
int edges[100000];
int edges_num;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> N >> M;
        memset(used, 0, N * 3 + 1);
        edges_num = 0;
        for (int i = 0; i < M; ++i) {
            int v1, v2;
            cin >> v1 >> v2;
            if (!used[v1] && !used[v2]) {
                edges[edges_num] = i + 1;
                ++edges_num;
                used[v1] = used[v2] = true;
            }
        }
        if (edges_num >= N) {
            cout << "Matching" << endl;
            for (int i = 0; i < N; ++i) {
                cout << edges[i] << ' ';
            }
            cout << endl;
        } else {
            cout << "IndSet" << endl;
            int index = 1;
            for (int i = 0; i < N; ++i) {
                while (used[index])
                    ++index;
                cout << index << ' ';
                ++index;
            }
            cout << endl;
        }
    }

    return 0;
}