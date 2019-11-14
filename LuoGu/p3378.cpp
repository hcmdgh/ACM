#include <iostream>
using namespace std;

const int MAXN = 1000005;
int heap[MAXN];
int heap_size = 0;
int N;

void push(int val) {
    heap[++heap_size] = val;
    int cur = heap_size;
    while (cur > 0) {
        int father = cur >> 1;
        if (heap[father] > heap[cur]) {
            swap(heap[father], heap[cur]);
        } else {
            break;
        }
        cur = father;
    }
}

void pop() {
    heap[1] = heap[heap_size];
    --heap_size;
    int cur = 1, son;
    while ((son = cur << 1) <= heap_size) {
        if (son + 1 <= heap_size && heap[son+1] < heap[son])
            ++son;
        if (heap[son] < heap[cur])
            swap(heap[son], heap[cur]);
        else
            break;
        cur = son;
    }
}

int top() {
    return heap[1];
}

int main() {
#ifdef DEBUG
    freopen("LuoGu/in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    while (N--) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 1) {
            int val;
            scanf("%d", &val);
            push(val);
        } else if (cmd == 2) {
            printf("%d\n", top());
        } else {
            pop();
        }
    }

    return 0;
}