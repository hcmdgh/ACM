#include <iostream>
#include <string>
using namespace std;

// N:人数 M:题目数
int N, M;
string answers[1000];
int points[1000];

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> answers[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> points[i];
    }

    int score = 0;
    for (int question = 0; question < M; ++question) {
        int max_count = 0;
        for (int answer = 0; answer < 5; ++answer) {
            char ans = 'A' + answer;
            int count = 0;
            for (int i = 0; i < N; ++i) {
                if (answers[i][question] == ans) {
                    ++count;
                }
            }
            max_count = max(max_count, count);
        }
        score += max_count * points[question];
    }

    cout << score << endl;

    return 0;
}