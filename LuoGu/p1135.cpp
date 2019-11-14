#include <iostream>
#include <algorithm>
using namespace std;

bool reached1[200];
bool reached2[200];
bool visited[200];
int steps[200];

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    if (A == B) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < N; ++i)
        cin >> steps[i];

    --A, --B;
    reached1[A] = visited[A] = true;
    int time = 0;
    while (true) {
        ++time;
        bool* src = (time & 1) ? reached1 : reached2;
        bool* dest = (time & 1) ? reached2 : reached1;
        bool valid = false;
        fill(dest, dest + N, false);
        for (int i = 0; i < N; ++i) {
            if (src[i]) {
                int temp = i + steps[i];
                if (temp < N) {
                    dest[temp] = true;
                    if (!visited[temp]) {
                        visited[temp] = true;
                        valid = true;
                    }
                }
                temp = i - steps[i];
                if (temp >= 0) {
                    dest[temp] = true;
                    if (!visited[temp]) {
                        visited[temp] = true;
                        valid = true;
                    }
                }
            }
        }
        if (dest[B]) {
            cout << time;
            break;
        }
        if (!valid) {
            cout << -1 << endl;
            break;
        }
    }

    return 0;
}