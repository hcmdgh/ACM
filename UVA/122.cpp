#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    bool hasValue;

    Node() : left(nullptr), right(nullptr), val(0), hasValue(false) {}
};

int main() {
    ios::sync_with_stdio(false);
    string str;
    while (true) {
        Node* root = new Node;
        bool valid = true;
        while (true) {
            if (!(cin >> str)) {
                return 0;
            } else if (str == "()") {
                break;
            }
            int length = str.length();
            int val = 0;
            bool negative = false;
            Node* cur = root;
            for (int i = 1; i < length; ++i) {
                if (str[i] == '-') {
                    negative = true;
                } else if (str[i] >= '0' && str[i] <= '9') {
                    val = val * 10 + str[i] - '0';
                } else if (str[i] == 'L') {
                    if (cur->left) {
                        cur = cur->left;
                    } else {
                        cur = cur->left = new Node;
                    }
                } else if (str[i] == 'R') {
                    if (cur->right) {
                        cur = cur->right;
                    } else {
                        cur = cur->right = new Node;
                    }
                }
            }
            if (negative)
                val = -val;
            if (cur->hasValue) {
                valid = false;
            }
            cur->val = val;
            cur->hasValue = true;
        }

        if (valid) {
            queue<Node*> q;
            queue<int> ans;
            q.emplace(root);
            while (!q.empty()) {
                Node* top = q.front();
                q.pop();
                if (top->left) {
                    q.emplace(top->left);
                }
                if (top->right) {
                    q.emplace(top->right);
                }
                if (top->hasValue) {
                    ans.emplace(top->val);
                } else {
                    valid = false;
                    break;
                }
                delete top;
            }
            if (valid) {
                cout << ans.front();
                ans.pop();
                while (!ans.empty()) {
                    cout << ' ' << ans.front();
                    ans.pop();
                }
                cout << endl;
            } else {
                cout << "not complete" << endl;
            }
        } else {
            cout << "not complete" << endl;
        }
    }

    return 0;
}