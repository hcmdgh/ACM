#include <iostream>
#include <string>
using namespace std;

char types[2048];
char str[1024];
int N;
int leavesNum;

void explore(int node, char type, int begin, int end) {
    types[node] = type;
    if (end <= begin)
        return;
    int left_begin = begin, left_end = (begin + end) / 2;
    int right_begin = left_end + 1, right_end = end;
    if (type == 'B' || type == 'I') {
        explore(node * 2 + 1, type, left_begin, left_end);
        explore(node * 2 + 2, type, right_begin, right_end);
    } else {
        char _type = 'B';
        for (int i = left_begin; i < left_end; ++i) {
            if (str[i] != str[i + 1]) {
                _type = 'F';
                break;
            }
        }
        if (_type != 'F')
            _type = (str[left_begin] == '0' ? 'B' : 'I');
        explore(node * 2 + 1, _type, left_begin, left_end);

        _type = 'B';
        for (int i = right_begin; i < right_end; ++i) {
            if (str[i] != str[i + 1]) {
                _type = 'F';
                break;
            }
        }
        if (_type != 'F')
            _type = (str[right_begin] == '0' ? 'B' : 'I');
        explore(node * 2 + 2, _type, right_begin, right_end);
    }
}

void post_order(int node) {
    if (node >= leavesNum)
        return;
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    post_order(left);
    post_order(right);
    cout << types[node];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    int length = 1 << N;
    leavesNum = length * 2 - 1;
    for (int i = 0; i < length; ++i) {
        cin >> str[i];
    }

    char type = 'B';
    for (int i = 0; i < length - 1; ++i) {
        if (str[i] != str[i + 1]) {
            type = 'F';
            break;
        }
    }
    if (type != 'F')
        type = (str[0] == '0' ? 'B' : 'I');
    explore(0, type, 0, length - 1);
    post_order(0);
    cout << endl;

    return 0;
}