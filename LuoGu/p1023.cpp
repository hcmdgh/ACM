#include <iostream>
using namespace std;

typedef long long ll;
int price2num[200005];

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int expected_price, cb, num_cb;
    scanf("%d%d%d", &expected_price, &cb, &num_cb);
    price2num[cb] = num_cb;
    int last_price = cb;
    int price, num;
    while (scanf("%d%d", &price, &num) == 2 && (price != -1 || num != -1)) {
        price2num[price] = num;
        if (price - last_price > 1) {
            int gap = (num - price2num[last_price]) / (price - last_price);
            for (int i = last_price + 1; i < price; ++i) {
                price2num[i] = price2num[i - 1] + gap;
            }
        }
        last_price = price;
    }
    int reduce;
    scanf("%d", &reduce);
    int max_price = last_price;
    while (price2num[max_price] > 0) {
        ++max_price;
        price2num[max_price] = price2num[max_price - 1] - reduce;
    }
    --max_price;
    int subsidy = 0;
    bool flag = false;
    while (true) {
        ll max_profit = 0;
        ll expected_profit = (expected_price - cb + subsidy) * price2num[expected_price];
        for (int i = cb; i <= max_price; ++i) {
            ll profit = ll(i - cb + subsidy) * price2num[i];
            max_profit = max(max_profit, profit);
        }
        if (max_profit == expected_profit) {
            printf("%d\n", subsidy);
            return 0;
        }
        if (flag)
            subsidy = -subsidy;
        else
            subsidy = (-subsidy) + 1;
        flag = !flag;
    }

    return 0;
}