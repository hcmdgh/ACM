#include <iostream>
#include <set>
using namespace std;

int T, L;
char complex[30];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &L, complex);
        for (int i = 0; i < L; ++i) {
            char cmd[5];
            scanf("%s", cmd);
            if (cmd[0] == 'F') {

            } else {

            }
        }
    }

    return 0;
}