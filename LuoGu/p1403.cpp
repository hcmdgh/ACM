#include <iostream>
using namespace std;

int a[1000001];

int main() {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            ++a[j];
        }
        count += a[i];
    }
    cout << count << endl;

    return 0;
}