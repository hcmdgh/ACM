#include <iostream>
#include <set>
using namespace std;

int N, I, H, R, A, B;
int diff[10005];
int arr[10005];
typedef pair<int, int> Pair;
set<Pair> used;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d%d%d", &N, &I, &H, &R);
    diff[1] = H;
    while (R--) {
        scanf("%d%d", &A, &B);
        if (A > B)
            swap(A, B);
        Pair p = Pair(A, B);
        if (!used.count(p)) {
            used.emplace(p);
            --diff[A + 1];
            ++diff[B];
        }
    }
    for (int i = 1; i <= N; ++i) {
        arr[i] = arr[i - 1] + diff[i];
    }
    for (int i = 1; i <= N; ++i) {
        printf("%d\n", arr[i]);
    }

    return 0;
}