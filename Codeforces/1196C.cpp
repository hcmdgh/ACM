#include <iostream>
using namespace std;

const int BOUND = 100000;

struct Range {
    int x1, x2, y1, y2;

    bool intersect(const Range& other) {
        x1 = max(x1, other.x1);
        y1 = max(y1, other.y1);
        x2 = min(x2, other.x2);
        y2 = min(y2, other.y2);
        return x1 <= x2 && y1 <= y2;
    }
} ranges[BOUND];

int main() {
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while (Q-- > 0) {
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            int x, y, up, right, down, left;
            cin >> x >> y >> up >> right >> down >> left;
            Range& range = ranges[i];
            if (up)
                range.x1 = -BOUND;
            else
                range.x1 = x;
            if (down)
                range.x2 = BOUND;
            else
                range.x2 = x;
            if (left)
                range.y1 = -BOUND;
            else
                range.y1 = y;
            if (right)
                range.y2 = BOUND;
            else
                range.y2 = y;
        }

        Range& range = ranges[0];
        bool valid = true;
        for (int i = 1; i < N; ++i) {
            if (!range.intersect(ranges[i])) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << "1 " << range.x1 << ' ' << range.y1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}