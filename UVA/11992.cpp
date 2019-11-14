#include <iostream>
#include <cstring>
using namespace std;

#define LEFT_CHILD(node) ((node) << 1)
#define RIGHT_CHILD(node) (((node) << 1) ^ 1)

const int MAXN = 1000005;
int R, C, M;
int op_left, op_right, int op_val;

struct IntervalTree {
    int* _max = nullptr;
    int* _min = nullptr;
    int* sum = nullptr;
    int* tag_add = nullptr;
    int* tag_set = nullptr;

    void init() {
        delete [] _max;
        delete [] _min;
        delete [] sum;
        delete [] tag_add;
        delete [] tag_set;
        _max = new int[C << 2]();
        _min = new int[C << 2]();
        sum = new int[C << 2]();
        tag_add = new int[C << 2];
        tag_set = new int[C << 2];
        memset(tag_add, 0xFF, sizeof(int) * (C<<2));
        memset(tag_set, 0xFF, sizeof(int) * (C<<2));
    }

    void push_down(int node, int node_left, int node_right) {
        int left_child = LEFT_CHILD(node);
        int right_child = RIGHT_CHILD(node);
        int mid = (node_left + node_right) >> 1;

    }
} trees[21];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    while (scanf("%d%d%d", &R, &C, &M) == 3) {
        for (int i = 1; i <= R; ++i) {
            trees[i].init();
        }
        while (M--) {

        }
    }

    return 0;
}
