#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

typedef pair<int, int> Matrix;
map<char, Matrix> _map;

int N;
struct Node {
    int height, width;
    int val;
};

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        char ch;
        Matrix m;
        cin >> ch >> m.first >> m.second;
        _map[ch] = m;
    }

    string expr;
    while (cin >> expr) {
        stack<Node> s;
        bool valid = true;
        for (char ch : expr) {
            if (ch == '(') {
                s.push({-1, -1, -1});
            } else if (ch == ')') {
                Node top = s.top();
                s.pop();
                s.pop();
                if (!s.empty() && s.top().height != -1) {
                    Node top2 = s.top();
                    s.pop();
                    if (top2.width != top.height) {
                        valid = false;
                        break;
                    }
                    s.push({top2.height, top.width, top2.val + top.val + top2.height * top2.width * top.width});
                } else {
                    s.push(top);
                }
            } else {
                Matrix matrix = _map[ch];
                if (!s.empty() && s.top().height != -1) {
                    Node top = s.top();
                    s.pop();
                    if (top.width != matrix.first) {
                        valid = false;
                        break;
                    }
                    s.push({top.height, matrix.second, top.val + top.height * top.width * matrix.second});
                } else {
                    s.push({matrix.first, matrix.second, 0});
                }
            }
        }

        if (valid) {
            assert(s.size() == 1);
            cout << s.top().val << endl;
        } else {
            cout << "error" << endl;
        }
    }

    return 0;
}