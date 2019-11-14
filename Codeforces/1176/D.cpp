#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int MAX_PRIME = 2750131;
const int PRIMES_COUNT = 199999;
bool is_prime[MAX_PRIME + 1];
int primes[PRIMES_COUNT];
int origin_array[200000];
map<int, int> num2count;

void init() {
    fill(is_prime + 2, is_prime + MAX_PRIME + 1, true);
    for (int i = 2; i * i < MAX_PRIME; ++i) {
        if (is_prime[i]) {
            for (int j = i * 2; j <= MAX_PRIME; j += i) {
                is_prime[j] = false;
            }
        }
    }
    int j = 2;
    for (int i = 0; i < PRIMES_COUNT; ++i) {
        while (!is_prime[j])
            ++j;
        primes[i] = j;
        ++j;
    }
}

int main() {
    ios::sync_with_stdio(false);

    init();
    int N;
    cin >> N;
    for (int i = 0; i < N * 2; ++i) {
        int input;
        cin >> input;
        if (num2count.count(input) == 0) {
            num2count.insert(pair<int, int>(input, 1));
        } else {
            ++num2count[input];
        }
    }

    int id = 0;
    for (auto& elem : num2count) {
        int num = elem.first;
        while (elem.second > 0) {
            if (is_prime[num]) {
                if (num2count[primes[num - 1]] > 0) {
                    --elem.second;
                    --num2count[primes[num - 1]];
                    origin_array[id++] = num;
                } else {
                    cout << "ERROR!" << endl;
                }
            } else {

            }
        }
    }

    return 0;
}