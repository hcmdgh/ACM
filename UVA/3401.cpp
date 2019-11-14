#include <cstdio>
#include <cstring>
using namespace std;

int N;
char colors[4][6][25];
const int perms[24][6] = {
    {1, 2, 3, 4, 5, 6},
    {2, 6, 3, 4, 1, 5},
    {6, 5, 3, 4, 2, 1},
    {5, 1, 3, 4, 6, 2},

    {2, 1, 4, 3, 6, 5},
    {6, 2, 4, 3, 5, 1},
    {5, 6, 4, 3, 1, 2},
    {1, 5, 4, 3, 2, 6},
};

int main() {
    while (scanf("%d", &N) == 1 && N > 0) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 6; ++j) {
                scanf("%s", colors[i][j]);
            }
        }


    }

    return 0;
}
