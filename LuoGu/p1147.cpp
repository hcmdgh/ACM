#include <iostream>
#include <stack>
using namespace std;

stack<pair<int, int>> results;

void calc(int a, int b) {
    int _l = a - b + 1;
    int _r = a + b - 1;
    int l = _l / 2;
    int r = _r / 2;
    if (l < r && l > 0 && _l % 2 == 0 && _r % 2 == 0) {
        results.emplace(pair<int, int>(l, r));
    }
}

int main() {
    int M;
    cin >> M;
    M *= 2;
    for (int i = 2; i * i <= M; ++i) {
        if (M % i == 0) {
            calc(i, M / i);
            calc(M / i, i);
        }
    }

    while (!results.empty()) {
        cout << results.top().first << ' ' << results.top().second << endl;
        results.pop();
    }

    return 0;
}