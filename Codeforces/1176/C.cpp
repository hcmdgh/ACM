#include <iostream>
#include <map>
using namespace std;

const int SAMPLE[6] = {4, 8, 15, 16, 23, 42};
int counts[6];  // counts[0]表示长度为1的序列个数
map<int, int> num2pos;

int main() {
    for (int i = 0; i < 6; ++i) {
        num2pos.emplace(pair<int, int>(SAMPLE[i], i));
    }

    int N;
    cin >> N;
    int result = 0;
    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        int pos = num2pos[input];
        if (pos == 0) {
            ++counts[0];
        } else {
            if (counts[pos - 1] > 0) {
                --counts[pos - 1];
                ++counts[pos];
            } else {
                ++result;
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        result += counts[i] * (i + 1);
    }

    cout << result << endl;

    return 0;
}