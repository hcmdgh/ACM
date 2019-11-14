#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int K;
int arr[755][755];
struct Item {
    int ib, sum;

    bool operator<(const Item& other) const {
        return sum > other.sum;
    }
};

void merge(int a[], int b[], int res[]) {
    priority_queue<Item> pq;
    for (int i = 0; i < K; ++i) {
        Item item;
        item.ib = 0;
        item.sum = a[i] + b[0];
        pq.emplace(item);
    }
    for (int i = 0; i < K; ++i) {
        Item top = pq.top();
        pq.pop();
        res[i] = top.sum;
        if (top.ib < K - 1) {
            ++top.ib;
            top.sum = top.sum - b[top.ib-1] + b[top.ib];
            pq.emplace(top);
        }
    }
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    while (scanf("%d", &K) == 1) {
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < K; ++j) {
                scanf("%d", &arr[i][j]);
            }
            sort(arr[i], arr[i] + K);
        }
        for (int i = 1; i < K; ++i) {
            merge(arr[0], arr[i], arr[0]);
        }
        printf("%d", arr[0][0]);
        for (int i = 1; i < K; ++i) {
            printf(" %d", arr[0][i]);
        }
        putchar('\n');
    }

    return 0;
}
