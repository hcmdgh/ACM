#include <iostream>
#include <cstring>
using namespace std;

char N[2030];

int main() {
    scanf("%s", N);
    int len = strlen(N);
    int digit = N[len - 1] - '0';
    if (digit & 1) {
        printf("-1\n");
    } else {
        printf("1\n");
    }

    return 0;
}