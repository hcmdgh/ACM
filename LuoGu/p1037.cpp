#include <iostream>
#include <vector>
#include <set>
using namespace std;

char num[35];
int K;
vector<int> rules[10];
typedef long long ll;
set<int> visited;
int ans[50];

void dfs(int digit) {
    if (visited.count(digit))
        return;
    visited.emplace(digit);
    for (int i : rules[digit]) {
        dfs(i);
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%s%d", num, &K);
    while (K--) {
        int from, to;
        scanf("%d%d", &from, &to);
        rules[from].emplace_back(to);
    }
    ans[0] = 1;
    for (char* ch = num; *ch; ++ch) {
        int digit = *ch - '0';
        visited.clear();
        dfs(digit);
        int res = visited.size();
        int carry = 0;
        for (int i = 0; i < 49; ++i) {
            int temp = ans[i] * res + carry;
            ans[i] = temp % 10;
            carry = temp / 10;
        }
    }
    int pos = 49;
    while (ans[pos] == 0)
        --pos;
    while (pos >= 0) {
        putchar('0' + ans[pos]);
        --pos;
    }

    return 0;
}