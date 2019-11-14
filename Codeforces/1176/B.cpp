#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;
        for (int j = 0; j < N; ++j) {
            int input;
            cin >> input;
            switch (input % 3) {
                case 0:
                    ++count_0;
                    break;
                case 1:
                    ++count_1;
                    break;
                default:
                    ++count_2;
            }
        }
        int temp = min(count_1, count_2);
        int result = count_0 + temp;
        count_1 -= temp;
        count_2 -= temp;
        result += count_1 / 3 + count_2 / 3;
        cout << result << endl;
    }

    return 0;
}