#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[105];

struct Gap {
    int begin, end, color;

    int len() const {
        return end - begin + 1;
    }

    bool operator<(const Gap& other) const {
        return len() < other.len();
    }
};

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d", &N) == 1) {
        int one = 0, zero = 0;
        for (int i = 1; i <= N; ++i) {
            int num;
            scanf("%d", &num);
            if (num == 0) {
                arr[i] = -1;
            } else if (num & 1) {
                ++one;
                arr[i] = 1;
            } else {
                ++zero;
                arr[i] = 0;
            }
        }
        int complexity = 0;
        for (int i = 1; i < N; ++i) {
            if (arr[i] != -1 && arr[i + 1] != -1 && arr[i] != arr[i + 1]) {
                ++complexity;
            }
        }
        zero = N / 2 - zero;
        one = (N + 1) / 2 - one;
        int begin = 999, end = -1;
        arr[0] = -1;
        arr[N + 1] = -2;
        vector<Gap> same_gaps, different_gaps, one_gaps;
        for (int i = 1; i <= N + 1; ++i) {
            if (arr[i] == -1) {
                begin = min(begin, i);
                end = max(end, i);
            } else {
                if (end - begin + 1 > 0) {
                    if (begin == 1) {
                        one_gaps.push_back({begin, end, arr[end + 1]});
                    } else if (end == N) {
                        one_gaps.push_back({begin, end, arr[begin - 1]});
                    } else if (arr[begin - 1] == arr[end + 1]) {
                        same_gaps.push_back({begin, end, arr[begin - 1]});
                    } else {
                        different_gaps.push_back({begin, end, -1});
                    }
                }
                begin = 999;
            }
        }
        if (same_gaps.size() == 1 && same_gaps[0].color == -2) {
            printf("%d\n", (N > 1 ? 1 : 0));
            continue;
        }
        sort(same_gaps.begin(), same_gaps.end());
        for (const auto& gap : same_gaps) {
            if (gap.color == 0) {
                if (zero >= gap.len()) {
                    zero -= gap.len();
                } else {
                    complexity += 2;
                }
            } else {
                if (one >= gap.len()) {
                    one -= gap.len();
                } else {
                    complexity += 2;
                }
            }
        }
        for (const auto& gap : one_gaps) {
            if (gap.color == 0) {
                if (zero >= gap.len()) {
                    zero -= gap.len();
                } else {
                    complexity += 1;
                }
            } else {
                if (one >= gap.len()) {
                    one -= gap.len();
                } else {
                    complexity += 1;
                }
            }
        }
        complexity += different_gaps.size();
        printf("%d\n", complexity);
    }

    return 0;
}