#include <cstdio>
#include <cfloat>
#include <cmath>
using namespace std;

#define SQUARE(x) ((x)*(x))

int N;
double positions_x[15];
double positions_y[15];
bool visited[15];
double min_distance = DBL_MAX;

void dfs(int step, double x, double y, double distance) {
    if (step > N) {
        if (distance < min_distance) {
            min_distance = distance;
        }
    } else if (distance < min_distance) {
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                double _distance = sqrt(SQUARE(x-positions_x[i]) + SQUARE(y-positions_y[i]));
                visited[i] = true;
                dfs(step + 1, positions_x[i], positions_y[i], distance + _distance);
                visited[i] = false;
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%lf", positions_x + i);
        scanf("%lf", positions_y + i);
    }

    dfs(1, 0, 0, 0);

    printf("%.2lf\n", min_distance);

    return 0;
}