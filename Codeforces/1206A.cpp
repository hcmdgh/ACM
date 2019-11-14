#include <iostream>
#include <set>
using namespace std;

int N, M;
set<int> setA, setB;

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    int val;
    for (int i = 0; i < N; ++i) {
        cin >> val;
        setA.emplace(val);
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> val;
        setB.emplace(val);
    }

    for (auto it1 = setA.begin(); it1 != setA.end(); ++it1) {
        for (auto it2 = setB.begin(); it2 != setB.end(); ++it2) {
            int sum = *it1 + *it2;
            if (setA.count(sum) == 0 && setB.count(sum) == 0) {
                cout << *it1 << ' ' << *it2 << endl;
                return 0;
            }
        }
    }

    return 0;
}
