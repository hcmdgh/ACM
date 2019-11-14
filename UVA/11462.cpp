#include <iostream>
#include <cstring>
using namespace std;

inline int readInt(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

int N;
int cnt[105];

int main() {
    while ((N = readInt()) > 0) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < N; ++i) {
            int age = readInt();
            ++cnt[age];
        }
        bool first = true;
        for (int i = 1; i < 100; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                if (!first)
                    putchar(' ');
                else
                    first = false;
                printf("%d", i);
            }
        }
        putchar('\n');
    }

    return 0;
}
