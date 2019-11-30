#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int N;
char names[15][20];
int sent[15], received[15];

struct CMP {
    bool operator()(const char* name1, const char* name2) {
        return strcmp(name1, name2) < 0;
    }
};

map<char*, int, CMP> name2idx;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", names[i]);
        name2idx[names[i]] = i;
    }
//    for (auto item : name2idx) {
//        printf("%s,%d\n", item.first, item.second);
//    }
    char name[20];
    int num, money;
    while (scanf("%s%d%d", name, &money, &num) == 3) {
        int idx = name2idx[name];
        if (num == 0) {
            sent[idx] = 0;
        } else {
            int per = money / num;
            sent[idx] = per * num;
            for (int i = 0; i < num; ++i) {
                char _name[20];
                scanf("%s", _name);
                received[name2idx[_name]] += per;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        printf("%s %d\n", names[i], received[i] - sent[i]);
    }

    return 0;
}