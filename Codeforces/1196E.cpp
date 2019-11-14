#include <iostream>
using namespace std;

typedef pair<int, int> Point;
Point blacks[100000], whites[100000];

int main() {
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while (Q-- > 0) {
        int B, W;
        cin >> B >> W;
        bool flag = false;
        if (B < W) {  // 确保白色的数量较小
            swap(B, W);
            flag = true;
        }
        if (B > 3 * W + 1) {
            cout << "NO" << endl;
        } else {
            for (int i = 0; i < W; ++i) {
                whites[i].first = 2;
                whites[i].second = 2 * (i + 1);
                blacks[i].first = 2;
                blacks[i].second = 2 * i + 1;
            }
            int lengthB = W;
            if (B > lengthB) {
                blacks[lengthB].first = 2;
                blacks[lengthB].second = W * 2 + 1;
                ++lengthB;
            }
            if (B > lengthB) {
                for (int i = 0; i < W; ++i) {
                    blacks[lengthB].first = 1;
                    blacks[lengthB].second = 2 * (i + 1);
                    ++lengthB;
                    if (lengthB >= B)
                        break;
                }
                if (B > lengthB) {
                    for (int i = 0; i < W; ++i) {
                        blacks[lengthB].first = 3;
                        blacks[lengthB].second = 2 * (i + 1);
                        ++lengthB;
                    }
                }
            }

            cout << "YES" << endl;
            for (int i = 0; i < W; ++i) {
                if (flag) {
                    ++whites[i].second;
                }
                cout << whites[i].first << ' ' << whites[i].second << endl;
            }
            for (int i = 0; i < B; ++i) {
                if (flag) {
                    ++blacks[i].second;
                }
                cout << blacks[i].first << ' ' << blacks[i].second << endl;
            }
        }
    }

    return 0;
}