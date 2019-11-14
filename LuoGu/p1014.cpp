#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    int row = sqrt(2 * N);
    while (row * (row + 1) / 2 < N)
        ++row;

    int begin = row * (row - 1) / 2 + 1;
    if (row % 2 == 0) {
        cout << N - begin + 1 << '/' << row - (N - begin) << endl;
    } else {
        cout << row - (N - begin) << '/' << N - begin + 1 << endl;
    }

    return 0;
}