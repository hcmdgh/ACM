#include <iostream>
#include <deque>
using namespace std;

int layout[3000][3000];
int _layout[3000][3000];

int main() {
    ios::sync_with_stdio(false);
    int N, M, A, B, X, Y, Z;
    long long G;
    deque<int> dq;
    cin >> N >> M >> A >> B;
    cin >> G >> X >> Y >> Z;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            layout[i][j] = G;
            G = (G * X + Y) % Z;
        }
    }

    for (int i = 0; i < N; ++i) {
        dq.clear();
        for (int j = 0; j < M; ++j) {
            int& num = layout[i][j];
            if (!dq.empty() && dq.front() <= j - B)
                dq.pop_front();
            while (!dq.empty() && layout[i][dq.back()] >= num)
                dq.pop_back();
            dq.push_back(j);
            _layout[i][j] = layout[i][dq.front()];
        }
    }

    for (int j = B - 1; j < M; ++j) {
        dq.clear();
        for (int i = 0; i < N; ++i) {
            int& num = _layout[i][j];
            if (!dq.empty() && dq.front() <= i - A)
                dq.pop_front();
            while (!dq.empty() && _layout[dq.back()][j] >= num)
                dq.pop_back();
            dq.push_back(i);
            layout[i][j] = _layout[dq.front()][j];
        }
    }

    long long sum = 0;
    for (int i = A - 1; i < N; ++i) {
        for (int j = B - 1; j < M; ++j) {
            sum += layout[i][j];
        }
    }

    cout << sum << endl;

    return 0;
}