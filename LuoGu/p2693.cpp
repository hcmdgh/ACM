#include <iostream>
#include <set>
using namespace std;

int N;
struct Pair {
    int x, y, z;

    bool operator<(const Pair& other) const {
        if (x == other.x) {
            if (y == other.y) {
                return z < other.z;
            } else {
                return y < other.y;
            }
        } else {
            return x < other.x;
        }
    }
} pair1, pair2;
set<Pair> pairs;

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    cin >> pair1.x >> pair1.y >> pair1.z;
    cin >> pair2.x >> pair2.y >> pair2.z;

    pairs.insert(pair1);
    pairs.insert(pair2);
    for (int i = -2; i <= 2; ++i) {
        for (int j = -2; j <= 2; ++j) {
            for (int k = -2; k <= 2; ++k) {
                int x = (pair1.x + i + N) % N;
                if (x == 0) x = N;
                int y = (pair1.y + j + N) % N;
                if (y == 0) y = N;
                int z = (pair1.z + k + N) % N;
                if (z == 0) z = N;
                Pair temp{x, y, z};
                pairs.insert(temp);
            }
        }
    }
    for (int i = -2; i <= 2; ++i) {
        for (int j = -2; j <= 2; ++j) {
            for (int k = -2; k <= 2; ++k) {
                int x = (pair2.x + i + N) % N;
                if (x == 0) x = N;
                int y = (pair2.y + j + N) % N;
                if (y == 0) y = N;
                int z = (pair2.z + k + N) % N;
                if (z == 0) z = N;
                Pair temp{x, y, z};
                pairs.insert(temp);
            }
        }
    }

    cout << pairs.size() << endl;

    return 0;
}