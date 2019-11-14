#include <iostream>
#include <set>
using namespace std;

struct Plan {
    int begin, end;

    bool operator<(const Plan& other) const {
        return end < other.begin;
    }
};
int N;
char buffer[10];

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
    scanf("%d", &N);
    set<Plan> plans;
    while (N--) {
        scanf("%s", buffer);
        if (buffer[0] == 'A') {
            Plan new_plan;
            scanf("%d%d", &new_plan.begin, &new_plan.end);
            set<Plan>::iterator iter;
            int cnt = 0;
            while ((iter = plans.find(new_plan)) != plans.end()) {
                plans.erase(iter);
                ++cnt;
            }
            plans.emplace(new_plan);
            printf("%d\n", cnt);
        } else {
            printf("%d\n", plans.size());
        }
    }

    return 0;
}
