#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N;
int triples[100005][3];
vector<int> pos[100005];
int perm[100005];
bool visited[100005];

int find_remain(int num1, int num2) {
    vector<int>& pos1 = pos[num1];
    vector<int>& pos2 = pos[num2];
    set<int> _pos;
    for (int i : pos1) {
        _pos.emplace(i);
    }
    vector<int> pos3;
    for (int i : pos2) {
        if (_pos.count(i)) {
            pos3.emplace_back(i);
        }
    }
    for (int i : pos3) {
        for (int j = 0; j < 3; ++j) {
            int num = triples[i][j];
            if (!visited[num]) {
                return num;
            }
        }
    }
    return -1;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N - 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            int val;
            scanf("%d", &val);
            triples[i][j] = val;
            pos[val].emplace_back(i);
        }
    }
    int first = -1, last = -1;
    int second = -1, last2 = -1;
    for (int i = 1; i <= N; ++i) {
        if (pos[i].size() == 1) {
            if (first == -1) {
                first = i;
                perm[0] = i;
            } else {
                last = i;
                perm[N - 1] = i;
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (pos[i].size() == 2) {
            if (find_remain(first, i) != -1) {
                second = i;
                perm[1] = i;
            } else if (find_remain(last, i) != -1) {
                last2 = i;
                perm[N - 2] = i;
            }
        }
    }

    visited[first] = visited[second] = visited[last] = visited[last2] = true;
    for (int i = 2; i < N - 2; ++i) {
        int num1 = perm[i - 2];
        int num2 = perm[i - 1];
        int num3 = find_remain(num1, num2);
//        printf("%d\n", num3);
        visited[num3] = true;
        perm[i] = num3;
    }
    printf("%d", perm[0]);
    for (int i = 1; i < N; ++i) {
        printf(" %d", perm[i]);
    }
    putchar('\n');

    return 0;
}