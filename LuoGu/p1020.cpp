#include <iostream>
using namespace std;

int N = 0;
int weight[100005];
int sequence[100005];
int size;

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    while (scanf("%d", weight + N) == 1) {
        ++N;
    }

    // 最长不上升子序列
    sequence[0] = weight[0];
    size = 1;
    for (int i = 1; i < N; ++i) {
        int _weight = weight[i];
        if (_weight <= sequence[size - 1]) {
            sequence[size++] = _weight;
        } else {
            int begin = 0, end = size;
            while (begin <= end) {
                int mid = (begin + end) >> 1;
                if (sequence[mid] < _weight) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            }
            sequence[begin] = _weight;
        }
    }
    printf("%d\n", size);

    // 最长上升子序列
    sequence[0] = weight[0];
    size = 1;
    for (int i = 1; i < N; ++i) {
        int _weight = weight[i];
        if (_weight > sequence[size - 1]) {
            sequence[size++] = _weight;
        } else {
            int begin = 0, end = size;
            while (begin <= end) {
                int mid = (begin + end) >> 1;
                if (sequence[mid] >= _weight) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            }
            sequence[begin] = _weight;
        }
    }
    printf("%d\n", size);

    return 0;
}
