#include <iostream>
using namespace std;

int N, M;
struct Person {
    char name[15];
    int face;
} persons[100005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 0; i < N; ++i) {
            scanf("%d%s", &persons[i].face, persons[i].name);
        }
        int pos = 0;
        while (M--) {
            int direction, cnt;
            scanf("%d%d", &direction, &cnt);
            if (direction == persons[pos].face)
                cnt = -cnt;
            pos = (pos + cnt + N) % N;
        }
        printf("%s\n", persons[pos].name);
    }

    return 0;
}