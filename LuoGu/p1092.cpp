#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 26;

int N;
bool used[MAX_N] = {false};
int char2int[MAX_N];
int addend1[MAX_N];
int addend2[MAX_N];
int sum[MAX_N];
int perm_order[MAX_N];

void add_perm_order(int id) {
    static int index = 0;
    if (!used[id]) {
        used[id] = true;
        perm_order[index] = id;
        ++index;
    }
}

void perm(int index) {
    // 剪枝
    if (char2int[addend1[0]] + char2int[addend2[0]] >= N)
        return;
    for (int i = N - 1; i >= 0; --i) {
        int _addend1 = char2int[addend1[i]];
        int _addend2 = char2int[addend2[i]];
        int _sum = char2int[sum[i]];
        if (_addend1 == -1 || _addend2 == -1 || _sum == -1)
            continue;
        if ((_addend1 + _addend2) % N != _sum && (_addend1 + _addend2 + 1) % N != _sum)
            return;
    }

    if (index >= N) {
        bool valid = true;
        int carry = 0;
        for (int i = N - 1; i >= 0; --i) {
            int temp_sum = char2int[addend1[i]] + char2int[addend2[i]] + carry;
            if (char2int[sum[i]] != temp_sum % N) {
                valid = false;
                break;
            }
            carry = temp_sum / N;
        }
        if (valid) {
            for (int i = 0; i < N; ++i) {
                cout << char2int[i] << " ";
            }
            cout << endl;
            exit(0);
        }
    } else {
        int _index = perm_order[index];
        for (int i = N - 1; i >= 0; --i) {
            if (!used[i]) {
                used[i] = true;
                char2int[_index] = i;
                perm(index + 1);
                used[i] = false;
            }
        }
        char2int[_index] = -1;
    }
}

void input_arr(int arr[]) {
    for (int i = 0; i < N; ++i) {
        char ch;
        cin >> ch;
        arr[i] = ch - 'A';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    input_arr(addend1);
    input_arr(addend2);
    input_arr(sum);

    for (int i = N - 1; i >= 0; --i) {
        add_perm_order(addend1[i]);
        add_perm_order(addend2[i]);
        add_perm_order(sum[i]);
    }
    fill(char2int, char2int + N, -1);
    fill(used, used + N, false);
    perm(0);

    return 0;
}