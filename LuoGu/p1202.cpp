#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 > 0) || year % 400 == 0;
}
const int monthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int weekDayCount[7];

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    int weekDay = 0;
    for (int year = 1900; year < 1900 + N; ++year) {
        bool leap = isLeapYear(year);
        for (int month = 1; month <= 12; ++month) {
            int days = monthDay[month];
            if (leap && month == 2)
                ++days;
            for (int day = 1; day <= days; ++day) {
                weekDay = (weekDay + 1) % 7;
                if (day == 13) {
                    ++weekDayCount[weekDay];
                }
            }
        }
    }

    for (int i = 6; i < 6 + 7; ++i) {
        cout << weekDayCount[i % 7] << ' ';
    }
    cout << endl;

    return 0;
}