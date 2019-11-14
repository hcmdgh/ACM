#include <cstdio>
using namespace std;

int N;
int src[50], dest[50];

int move_disk(int id, int dest_pillar) {
    int cnt = 0;
    if (src[id] != dest_pillar) {
        for (int i = id - 1; i >= 1; --i) {
            cnt += move_disk(i, 6 - src[id] - dest_pillar);
        }
        printf("move %d from %c to %c\n", id, src[id]+'A'-1, dest_pillar+'A'-1);
        src[id] = dest_pillar;
        ++cnt;
    }
    return cnt;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= 3; ++i) {
        int num;
        scanf("%d", &num);
        while (num--) {
            int id;
            scanf("%d", &id);
            src[id] = i;
        }
    }
    for (int i = 1; i <= 3; ++i) {
        int num;
        scanf("%d", &num);
        while (num--) {
            int id;
            scanf("%d", &id);
            dest[id] = i;
        }
    }

    int cnt = 0;
    for (int i = N; i >= 1; --i) {
        cnt += move_disk(i, dest[i]);
    }
    printf("%d\n", cnt);

    return 0;
}
