#include <iostream>
#include <cstring>

using namespace std;

bool exist[100];

int main() {
    int N, M;
    cin >> N >> M;

    memset(exist, 1, N);
    int remaining = N;
    int cur = -1;
    while (remaining > 0) {
        for (int i = 0; i < M;) {
            cur = (cur + 1) % N;
            if (exist[cur])
                ++i;
        }
        --remaining;
        exist[cur] = false;
        cout << cur + 1 << ' ';
    }

    return 0;
}