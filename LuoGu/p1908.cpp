#include <iostream>
#include <algorithm>
using namespace std;

#define LOWBIT(x) ((x)&(-(x)))

int N;
int num[500000];
int order[500000];
long long tree[500001];

void update(int i) {
    while (i <= N) {
        ++tree[i];
        i += LOWBIT(i);
    }
}

int sum(int i) {
    int _sum = 0;
    while (i > 0) {
        _sum += tree[i];
        i -= LOWBIT(i);
    }
    return _sum;
}

bool cmp(int val1, int val2) {
    int num1 = num[val1 - 1];
    int num2 = num[val2 - 1];
    if (num1 == num2)
        return val1 > val2;
    return num1 > num2;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> num[i];
        order[i] = i + 1;
    }

    sort(order, order + N, cmp);
    long long result = 0;
    for (int i = 0; i < N; ++i) {
        int _order = order[i];
        update(_order);
        result += sum(_order - 1);
    }

    cout << result << endl;

    return 0;
}