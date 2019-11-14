#include <iostream>
using namespace std;

int get_distance(int x, int y) {
    int ans = 0;
    int temp = x ^ y;
    while (temp > 0) {
        temp ^= temp & (-temp);
        ++ans;
    }
    return ans;
}

int nums[64];

int main() {
    ios::sync_with_stdio(false);
    int N, B, D;
    cin >> N >> B >> D;

    int num = 1;
    for (int i = 1; i < N; ++i) {
        bool valid = false;
        while (!valid) {
            valid = true;
            for (int j = 0; j < i; ++j) {
                if (get_distance(num, nums[j]) < D) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                nums[i] = num;
            }
            ++num;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << nums[i];
        if ((i + 1) % 10 == 0 || i == N - 1) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }

    return 0;
}
