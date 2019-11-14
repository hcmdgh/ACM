#include <iostream>
#include <climits>
using namespace std;

char s1[105], s2[105];
int len1, len2;
int dp[105][105];
const int table[5][5] = {
    {5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,0},
};

int char2int(char ch) {
    if (ch == 'A')
        return 0;
    if (ch == 'C')
        return 1;
    if (ch == 'G')
        return 2;
    if (ch == 'T')
        return 3;
    return -1;
}

int match(int i, int j) {
    if (j == -1) {
        return table[s1[i]][4];
    } else if (i == -1) {
        return table[s2[j]][4];
    } else {
        return table[s1[i]][s2[j]];
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d%s", &len1, s1 + 1);
    scanf("%d%s", &len2, s2 + 1);
    for (int i = 1; i <= len1; ++i) {
        s1[i] = char2int(s1[i]);
    }
    for (int i = 1; i <= len2; ++i) {
        s2[i] = char2int(s2[i]);
    }
    for (int i = 1; i <= len1; ++i) {
        dp[i][0] = dp[i-1][0] + match(i, -1);
    }
    for (int j = 1; j <= len2; ++j) {
        dp[0][j] = dp[0][j-1] + match(-1, j);
    }
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            dp[i][j] = max(match(i, j) + dp[i-1][j-1],
                max(match(i, -1) + dp[i-1][j], match(-1, j) + dp[i][j-1]));
        }
    }
    printf("%d\n", dp[len1][len2]);

    return 0;
}
