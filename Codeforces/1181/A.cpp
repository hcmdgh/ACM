#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long X, Y, Z;
    cin >> X >> Y >> Z;

    long long max_num = (X + Y) / Z;
    cout << max_num << " ";

    if (X % Z == 0 || Y % Z == 0 || X / Z + Y / Z == max_num)
        cout << 0 << endl;
    else {
        long long temp = X / Z;
        long long X_low = temp * Z;
        long long X_high = (temp + 1) * Z;
        temp = Y / Z;
        long long Y_low = temp * Z;
        long long Y_high = (temp + 1) * Z;
        long long delta[4];
        delta[0] = X - X_low;
        delta[1] = X_high - X;
        delta[2] = Y - Y_low;
        delta[3] = Y_high - Y;
        sort(delta, delta + 4);
        cout << delta[0] << endl;
    }

    return 0;
}