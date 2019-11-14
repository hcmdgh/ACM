#include <iostream>
using namespace std;

struct Student {
    int left, right;
};

Student students[100001];

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    students[0].left = students[0].right = 1;
    students[1].left = students[1].right = 0;
    for (int i = 2; i <= N; ++i) {
        int K, P;
        cin >> K >> P;
        if (P == 0) {  // 插入到K号同学左边
            students[i].right = K;
            students[i].left = students[K].left;
            students[students[K].left].right = i;
            students[K].left = i;
        } else {
            students[i].right = students[K].right;
            students[i].left = K;
            students[students[K].right].left = i;
            students[K].right = i;
        }
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int X;
        cin >> X;
        if (students[X].left > -1) {
            students[students[X].left].right = students[X].right;
            students[students[X].right].left = students[X].left;
            students[X].left = students[X].right = -1;
        }
    }

    int cur = students[0].right;
    while (true) {
        cout << cur;
        cur = students[cur].right;
        if (cur > 0)
            cout << ' ';
        else
            break;
    }

    return 0;
}