#include <iostream>
#include <vector>
using namespace std;

int N, W, K;
int arr[35][35];
int sum[35];
int score[35];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d%d", &N, &W, &K);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &arr[i][j]);
            sum[i] += arr[i][j];
        }
    }
    int max_sum = -1;
    for (int i = 1; i <= N; ++i) {
        max_sum = max(max_sum, sum[i]);
    }
    vector<int> tops;
    for (int i = 1; i <= N; ++i) {
        if (sum[i] == max_sum) {
            tops.emplace_back(i);
        }
    }
    if (tops.size() == 1) {
        printf("%d\n", tops[0]);
    } else {
        int max_score = -1;
        for (int id : tops) {
            for (int i = 1; i <= N; ++i) {
                if (id != i) {
                    if (arr[id][i] > arr[i][id]) {
                        score[id] += W;
                    } else if (arr[id][i] == arr[i][id]) {
                        score[id] += K;
                    }
                }
                max_score = max(max_score, score[id]);
            }
        }
        vector<int> winners;
        for (int i = 1; i <= N; ++i) {
            if (score[i] == max_score) {
                winners.emplace_back(i);
            }
        }
        if (winners.size() == 1) {
            printf("%d\n", winners[0]);
        } else {
            printf("Tie\n");
        }
    }

    return 0;
}