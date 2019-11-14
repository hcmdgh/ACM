#include <iostream>
#include <algorithm>
using namespace std;

int L;
const int MAX_LENGTH = 100000;
int num[MAX_LENGTH];
int result1[MAX_LENGTH];
int result2[MAX_LENGTH];

void add(int left_length, int result[]) {
    fill(result, result + MAX_LENGTH, 0);
    int carry = 0;
    int right_length = L - left_length;
    int result_length = max(left_length, right_length);
    for (int i = 0; i < result_length; ++i) {
        int left = i < left_length ? num[left_length - 1 - i] : 0;
        int right = i < right_length ? num[L - 1 - i] : 0;
        int value = left + right + carry;
        carry = value / 10;
        value %= 10;
        result[i] = value;
    }
    if (carry > 0) {
        result[result_length] = carry;
    }
}

void print(int result[]) {
    int i = MAX_LENGTH - 1;
    while (i >= 0 && result[i] == 0)
        --i;
    if (i < 0)
        cout << 0 << endl;
    else {
        while (i >= 0) {
            cout << result[i];
            --i;
        }
        cout << endl;
    }
}

int compare(int result1[], int result2[]) {
    int i = MAX_LENGTH - 1;
    while (i >= 0 && result1[i] == 0)
        --i;
    int length1 = i + 1;
    i = MAX_LENGTH - 1;
    while (i >= 0 && result2[i] == 0)
        --i;
    int length2 = i + 1;
    if (length1 != length2)
        return length1 - length2;
    for (i = length1 - 1; i >= 0; --i) {
        if (result1[i] != result2[i])
            return result1[i] - result2[i];
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> L;
    for (int i = 0; i < L; ++i) {
        char ch;
        cin >> ch;
        num[i] = ch - '0';
    }

    int left_length = L / 2;
    while (true) {
        int right_length = L - left_length;
        if (left_length == right_length) {
            if (num[left_length] > 0) {
                add(left_length, result1);
//                cout << "the same" << endl;
                print(result1);
                break;
            }
        } else {
            bool valid1 = false, valid2 = false;
            if (num[left_length] > 0) {
                add(left_length, result1);
                valid1 = true;
            }
            if (num[right_length] > 0) {
                add(right_length, result2);
                valid2 = true;
            }
            if (valid1 || valid2) {
                if (valid1 && valid2) {
//                    cout << "to compare" << endl;
//                    print(result1);
//                    print(result2);
                    if (compare(result1, result2) < 0) {
                        print(result1);
                    } else {
                        print(result2);
                    }
                } else if (valid1) {
                    print(result1);
                } else {
                    print(result2);
                }
                break;
            }
        }
        ++left_length;
    }

    return 0;
}