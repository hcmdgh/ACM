#include <iostream>
using namespace std;

int T, N;
char arr[105];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d", &T) == 1) {
        while (T--) {
            scanf("%d", &N);
            scanf("%s", arr);
            int moment = 0;
            bool end = false;
            while (!end) {
                ++moment;
                end = true;
                for (int i = N - 2; i >= 0; --i) {
                    if (arr[i] == 'A') {
                        if (arr[i + 1] == 'P') {
                            arr[i + 1] = 'A';
                            end = false;
                        }
                    }
                }
            }
            printf("%d\n", moment - 1);
        }
    }

    return 0;
}