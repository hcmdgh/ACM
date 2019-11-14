#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 10005;
char A[MAXN], B[MAXN], C[MAXN];

int compare(const char num1[], const char num2[]) {
    for (int i = MAXN - 1; i >= 0; --i) {
        if (num1[i] < num2[i])
            return -1;
        if (num1[i] > num2[i])
            return 1;
    }
    return 0;
}

bool equals_0(const char num[]) {
    for (int i = 0; i < MAXN; ++i) {
        if (num[i] > 0)
            return false;
    }
    return true;
}

char* gcd() {
    char* num1 = A;
    char* num2 = B;
//    printf("num1:");
//    print(num1);
//    printf("\nnum2:");
//    print(num2);
//    putchar('\n');
    int cmp = compare(num1, num2);
    if (cmp < 0)
        swap(num1, num2);
    if (cmp == 0) {
        return num1;
    } else {
        if (equals_0(num1))
            return num2;
        if (equals_0(num2))
            return num1;
        memset(C, 0, sizeof(C));
        for (int i = 0; i < MAXN; ++i) {
            C[i] += num1[i] - num2[i];
            if (C[i] < 0) {
                C[i] += 10;
                --C[i + 1];
            }
        }
        memcpy(num1, C, sizeof(num1));
        return gcd();
    }
}

void read(char num[]) {
    scanf("%s", C);
    int length = strlen(C);
    for (int i = 0; i < length; ++i) {
        num[length - 1 - i] = C[i] - '0';
    }
}

void print(const char result[]) {
    int begin_pos = MAXN - 1;
    while (begin_pos >= 0 && result[begin_pos] == 0)
        --begin_pos;
    if (begin_pos < 0) {
        printf("0\n");
    } else {
        for (int i = begin_pos; i >= 0; --i) {
            putchar(result[i] + '0');
        }
        putchar('\n');
    }
}

int main() {
    read(A);
    read(B);
    char* result = gcd();
    print(result);

    return 0;
}
