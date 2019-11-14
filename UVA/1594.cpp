#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> arr;

struct Cmp {
    bool operator()(const vector<int>& v1, const vector<int>& v2) const {
        int length = v1.size();
        for (int i = 0; i < length; ++i) {
            if (v1[i] < v2[i])
                return true;
            else if (v1[i] > v2[i])
                return false;
        }
        return false;
    }
};

set<vector<int>, Cmp> _set;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        arr.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }
        _set.clear();
        _set.emplace(arr);
        bool loop = false;
        for (int i = 0; i < 1000; ++i) {
            int a1 = arr[0];
            for (int j = 0; j < N - 1; ++j) {
                arr[j] = abs(arr[j] - arr[j + 1]);
            }
            arr[N - 1] = abs(a1 - arr[N - 1]);
            bool zero = true;
            for (int j = 0; j < N; ++j) {
                if (arr[j] != 0) {
                    zero = false;
                    break;
                }
            }
            if (zero)
                break;
            auto res = _set.emplace(arr);
            if (!res.second) {
                loop = true;
                break;
            }
        }
        if (loop)
            cout << "LOOP" << endl;
        else
            cout << "ZERO" << endl;
    }

    return 0;
}
