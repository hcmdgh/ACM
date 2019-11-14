#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int N, B;
struct Component {
    int price, quality;

    bool operator<(const Component& other) const {
        return price < other.price;
    }
};
char str[25], _str[25];
map<string, vector<Component>> types;
int max_quality, min_quality;

bool judge(int quality) {
    int remain_money = B;
    for (auto& item : types) {
        vector<Component> components = item.second;
        bool valid = false;
        for (Component& component : components) {
            if (component.quality >= quality) {
                valid = true;
                remain_money -= component.price;
                break;
            }
        }
        if (!valid || remain_money < 0)
            return false;
    }
    return true;
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%d", &N, &B);
        max_quality = 0;
        min_quality = INT_MAX;
        types.clear();
        for (int i = 0; i < N; ++i) {
            scanf("%s", str);
            scanf("%s", _str);
            Component component;
            scanf("%d%d", &component.price, &component.quality);
            max_quality = max(max_quality, component.quality);
            min_quality = min(min_quality, component.quality);
            types[string(str, str + strlen(str))].emplace_back(component);
        }
        for (auto& item : types) {
            sort(item.second.begin(), item.second.end());
        }

        int begin = min_quality, end = max_quality;
        while (begin <= end) {
            int mid = begin + ((end - begin) >> 1);
            if (judge(mid)) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        printf("%d\n", end);
    }

    return 0;
}
