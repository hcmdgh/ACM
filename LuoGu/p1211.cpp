#include <iostream>
#include <set>
using namespace std;

int digits[9];
int N;
int unknowns[5];
set<int> digits_set;
int ans = 0;

bool check(int num, int length) {
    int cnt = 0;
    while (num > 0) {
        int digit = num % 10;
        num /= 10;
        if (digits_set.count(digit) == 0)
            return false;
        ++cnt;
    }
    return cnt == length;
}

void dfs(int pos) {
    if (pos >= 5) {
        int num1 = unknowns[0] * 100 + unknowns[1] * 10 + unknowns[2];
        int num2 = unknowns[3] * 10 + unknowns[4];
        int temp1 = num1 * unknowns[4];
        int temp2 = num1 * unknowns[3];
        int product = num1 * num2;
        if (check(num1, 3) && check(num2, 2) && check(temp1, 3)
            && check(temp2, 3) && check(product, 4)) {
            ++ans;
        }
    } else {
        for (int i = 0; i < N; ++i) {
            unknowns[pos] = digits[i];
            dfs(pos + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> digits[i];
        digits_set.insert(digits[i]);
    }

    dfs(0);
    cout << ans << endl;

    return 0;
}