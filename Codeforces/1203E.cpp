#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N;
int weight[150005];
set<int> weight_set;

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> weight[i];
    }

    sort(weight, weight + N);
    for (int i = 0; i < N; ++i) {
        int w = weight[i];
        if (w > 1 && weight_set.count(w - 1) == 0) {
            weight_set.emplace(w - 1);
        } else if (weight_set.count(w) == 0) {
            weight_set.emplace(w);
        } else {
            weight_set.emplace(w + 1);
        }
    }

    cout << weight_set.size() << endl;

    return 0;
}
