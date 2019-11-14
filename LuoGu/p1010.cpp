#include <iostream>
#include <vector>
using namespace std;

void print(int num) {
    vector<bool> vec;
    while (num > 0) {
        vec.emplace_back(num & 1);
        num >>= 1;
    }
    int length = vec.size();
    bool first = true;
    for (int i = length - 1; i >= 0; --i) {
        if (vec[i]) {
            if (!first) {
                cout << "+";
            } else {
                first = false;
            }
            if (i == 0) {
                cout << "2(0)";
            } else if (i == 1) {
                cout << "2";
            } else if (i == 2) {
                cout << "2(2)";
            } else {
                cout << "2(";
                print(i);
                cout << ")";
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    print(N);

    return 0;
}