#include <iostream>
using namespace std;

int main() {
    int score;
    cin >> score;

    int grade1 = score % 4;
    int grade2 = (score + 1) % 4;
    int grade3 = (score + 2) % 4;

    if (grade1 == 1) {
        cout << 0 << " A" << endl;
    } else if (grade2 == 1) {
        cout << 1 << " A" << endl;
    } else if (grade3 == 1) {
        cout << 2 << " A" << endl;
    } else if (grade1 == 3) {
        cout << 0 << " B" << endl;
    } else if (grade2 == 3) {
        cout << 1 << " B" << endl;
    } else if (grade3 == 3) {
        cout << 2 << " B" << endl;
    } else if (grade1 == 2) {
        cout << 0 << " C" << endl;
    } else if (grade2 == 2) {
        cout << 1 << " C" << endl;
    } else if (grade3 == 2) {
        cout << 2 << " C" << endl;
    } else if (grade1 == 0) {
        cout << 0 << " D" << endl;
    } else if (grade2 == 0) {
        cout << 1 << " D" << endl;
    } else if (grade3 == 0) {
        cout << 2 << " D" << endl;
    }

    return 0;
}