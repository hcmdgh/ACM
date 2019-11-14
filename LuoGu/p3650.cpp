#include <iostream>
#include <climits>
using namespace std;

#define SQUARE(x) ((x)*(x))

int N;
int arr[1000];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int min_cost = INT_MAX;
    for (int max_height = 17; max_height <= 117; ++max_height) {
        int min_height = max_height - 17;
        int cost = 0;
        for (int i = 0; i < N; ++i) {
            if (arr[i] > max_height) {
                cost += SQUARE(arr[i] - max_height);
            } else if (arr[i] < min_height) {
                cost += SQUARE(arr[i] - min_height);
            }
        }
        min_cost = min(min_cost, cost);
    }

    cout << min_cost << endl;

    return 0;
}