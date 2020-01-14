#include <iostream>
using namespace std;
void scan(int);
void print(int);

//void touteng() {
//    print(13);
//}

//void print(int x) {
//    cout << x << endl;
//    scan(x);
//}

void scan(int* ptr) {
    int val;
    cin >> val;
    *ptr = val;
}

int main() {
    int a = 5, b = 8;
    cout << sizeof(int) << endl;
    cout << sizeof(char*) << endl;
    cout << sizeof(long long*) << endl;
    return 0;
    scan(&a);
    scan(&b);
    cout << a << " " << b << endl;

    return 0;
}