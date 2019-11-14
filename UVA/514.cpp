#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int perm[1000];

int main() {
    ios::sync_with_stdio(false);
    int N;
    while ((cin >> N) && N > 0) {
        while ((cin >> perm[0]) && perm[0] != 0) {
            for (int i = 1; i < N; ++i) {
                cin >> perm[i];
            }
            bool valid = true;
            int dest = 0, src = 1;
            while (dest < N && valid) {
                if (src == perm[dest]) {
                    ++dest, ++src;
                } else if (!s.empty() && s.top() == perm[dest]) {
                    ++dest;
                    s.pop();
                } else if (src <= N) {
                    s.emplace(src);
                    ++src;
                } else {
                    valid = false;
                }
            }
            if (valid)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        cout << endl;
    }

    return 0;
}