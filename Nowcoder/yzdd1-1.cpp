#include <iostream>
#include <cstring>
using namespace std;

int T;
char buffer[1024];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%s", buffer);
        if (strcmp(buffer, "lansou") == 0) {
            printf("xianggu\n");
        } else {
            printf("lansou\n");
        }
    }

    return 0;
}