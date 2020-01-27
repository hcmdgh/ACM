#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int N, M;
vector<vector<string>> foods;
set<string> _set;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin >> N;
    foods.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> M;
        for (int j = 0; j < M; ++j) {
            string food;
            cin >> food;
            foods[i].emplace_back(food);
        }
    }
    for (int pos = 0; pos <= 15; ++pos) {
        _set.clear();
        for (int i = 0; i < N; ++i) {
            string temp;
            for (auto& food : foods[i]) {
                if (pos < food.length()) {
                    temp.push_back(food[pos]);
                }
            }
            _set.emplace(temp);
        }
        if (_set.size() == N) {
            cout << "Kokoa no kati." << endl;
            return 0;
        }
    }
    cout << "Kokoa no shippai." << endl;

    return 0;
}