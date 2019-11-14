#include <iostream>
using namespace std;

bool read(int& weight) {
    int wl, dl, wr, dr;
    cin >> wl >> dl >> wr >> dr;
    bool valid = true;
    if (wl == 0) {
        valid = read(wl) && valid;
    }
    if (wr == 0) {
        valid = read(wr) && valid;
    }
    valid = valid && (wl * dl == wr * dr);
    weight = wl + wr;
    return valid;
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int weight;
        bool valid = read(weight);
        if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        if (Q)
            cout << endl;
    }

    return 0;
}
