#include <iostream>
#include <cmath>
using namespace std;

int N;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &N);
    double total_score = 0;
    double total_credit = 0;
    for (int i = 0; i < N; ++i) {
        int type;
        double credit;
        double daily_score;
        double daily_rate;
        double mid_score;
        double mid_rate;
        double final_score;
        double final_rate;
        scanf("%d%lf%lf%lf%lf%lf%lf%lf", &type, &credit, &daily_score, &daily_rate, &mid_score, &mid_rate, &final_score, &final_rate);
        if (type != 2) {
            total_credit += credit;
            total_score += round(daily_score * daily_rate + mid_score * mid_rate + final_score * final_rate) * credit;
        }
    }
    double res = total_score / total_credit;
    printf("%.2f\n", res);

    return 0;
}