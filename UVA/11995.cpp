#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int N;
typedef pair<int, int> Pair;
Pair commands[1005];

bool test_stack() {
    stack<int> ds;
    for (int i = 0; i < N; ++i) {
        int command = commands[i].first;
        int val = commands[i].second;
        if (command == 1) {
            ds.emplace(val);
        } else {
            if (ds.empty())
                return false;
            int top = ds.top();
            ds.pop();
            if (top != val)
                return false;
        }
    }
    return true;
}

bool test_queue() {
    queue<int> ds;
    for (int i = 0; i < N; ++i) {
        int command = commands[i].first;
        int val = commands[i].second;
        if (command == 1) {
            ds.emplace(val);
        } else {
            if (ds.empty())
                return false;
            int top = ds.front();
            ds.pop();
            if (top != val)
                return false;
        }
    }
    return true;
}

bool test_priority_queue() {
    priority_queue<int> ds;
    for (int i = 0; i < N; ++i) {
        int command = commands[i].first;
        int val = commands[i].second;
        if (command == 1) {
            ds.emplace(val);
        } else {
            if (ds.empty())
                return false;
            int top = ds.top();
            ds.pop();
            if (top != val)
                return false;
        }
    }
    return true;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; ++i) {
            int command, val;
            scanf("%d%d", &command, &val);
            commands[i].first = command;
            commands[i].second = val;
        }
        int res = 0;
        if (test_stack())
            res += 1;
        if (test_queue())
            res += 2;
        if (test_priority_queue())
            res += 4;
        if (res == 0)
            printf("impossible\n");
        else if (res == 1)
            printf("stack\n");
        else if (res == 2)
            printf("queue\n");
        else if (res == 4)
            printf("priority queue\n");
        else
            printf("not sure\n");
    }

    return 0;
}
