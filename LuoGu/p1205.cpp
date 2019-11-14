#include <iostream>
#include <cstring>
using namespace std;

int N;
char src[10][10], dest[10][10], temp[10][10], _src[10][10];

bool equal(char arr1[][10], char arr2[][10]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr1[i][j] != arr2[i][j])
                return false;
        }
    }
    return true;
}

void rotate90() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            temp[j][N-1-i] = src[i][j];
        }
    }
}

void rotate180() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            temp[N-1-i][N-1-j] = src[i][j];
        }
    }
}

void rotate270() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            temp[N-1-j][i] = src[i][j];
        }
    }
}

void flip() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            temp[i][N-1-j] = src[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> src[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> dest[i][j];
        }
    }

    rotate90();
    if (equal(dest, temp)) {
        cout << 1 << endl;
        return 0;
    }

    rotate180();
    if (equal(temp, dest)) {
        cout << 2 << endl;
        return 0;
    }

    rotate270();
    if (equal(temp, dest)) {
        cout << 3 << endl;
        return 0;
    }

    flip();
    if (equal(temp, dest)) {
        cout << 4 << endl;
        return 0;
    }

    memcpy(_src, src, sizeof(src));
    memcpy(src, temp, sizeof(src));

    rotate90();
    if (equal(temp, dest)) {
        cout << 5 << endl;
        return 0;
    }

    rotate180();
    if (equal(temp, dest)) {
        cout << 5 << endl;
        return 0;
    }

    rotate270();
    if (equal(temp, dest)) {
        cout << 5 << endl;
        return 0;
    }

    if (equal(_src, dest)) {
        cout << 6 << endl;
    } else {
        cout << 7 << endl;
    }

    return 0;
}