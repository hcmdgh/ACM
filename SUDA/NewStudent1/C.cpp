#include <iostream>
using namespace std;

int N;

int main() {
    scanf("%d", &N);
    bool easy = true;
    for (int i = 0; i < N; ++i) {
        int val;
        scanf("%d", &val);
        if (!val)
            easy = false;
    }
    if (easy) {
        printf("EASY\n");
    } else {
        printf("HARD\n");
    }

    return 0;
}