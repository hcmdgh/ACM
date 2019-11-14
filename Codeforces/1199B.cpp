#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    double H, L;
    cin >> H >> L;
    double res = (L*L - H*H) / (2*H);
    cout << setprecision(20) <<  res << endl;

    return 0;
}