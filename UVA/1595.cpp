#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

map<int, vector<int>> points;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        points.clear();
        for (int i = 0; i < N; ++i) {
            int row, col;
            cin >> col >> row;
            auto iter = points.find(row);
            if (iter == points.end()) {
                vector<int> v = {col};
                points[row] = v;
            } else {
                iter->second.emplace_back(col);
            }
        }

        for (auto& item : points) {
            sort(item.second.begin(), item.second.end());
        }

        vector<int>& vec = points.begin()->second;
        double pivot = (vec[0] + vec[vec.size() - 1]) * 0.5;
        bool valid = true;
        for (auto& item : points) {
            vector<int>& _vec = item.second;
            int size = _vec.size();
            for (int i = 0; i <= size >> 1; ++i) {
                if (pivot - _vec[i] != _vec[size-i-1] - pivot) {
                    valid = false;
                    goto end;
                }
            }
        }
        end:
        if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }



    return 0;
}
