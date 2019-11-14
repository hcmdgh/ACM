#include <iostream>
#include <string>
using namespace std;

string X, Y;
int lenX, lenY;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> X >> Y;
        lenX = X.length();
        lenY = Y.length();
        int posX1 = -1, posY1 = -1;
        for (int i = lenY - 1; i >= 0; --i) {
            if (Y[i] == '1') {
                posY1 = i;
                break;
            }
        }
        for (int i = lenX - lenY + posY1; i >= 0; --i) {
            if (X[i] == '1') {
                posX1 = i;
                break;
            }
        }
        if (posX1 == -1 || posY1 == -1) {
            cout << 0 << endl;
        } else {
            cout << (lenX - posX1) - (lenY - posY1) << endl;
        }
    }

    return 0;
}
