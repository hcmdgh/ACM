#include <iostream>
#include <string>
using namespace std;

string str1[25];
string str2[25];
int N, M, Q;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> str1[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> str2[i];
    }
    cin >> Q;
    while (Q--) {
        int year;
        cin >> year;
        cout << str1[(year - 1) % N] << str2[(year - 1) % M] << endl;
    }

    return 0;
}