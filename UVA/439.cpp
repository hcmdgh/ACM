#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int DIRECTIONS_X[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int DIRECTIONS_Y[8] = {2, -2, 2, -2, 1, -1, 1, -1};
typedef pair<int, int> Point;
typedef pair<Point, int> Pair;
bool visited[10][10];

int main() {
    ios::sync_with_stdio(false);
    char ch1, ch2, ch3, ch4;
    while (cin >> ch1 >> ch2 >> ch3 >> ch4) {
        int src_x = ch1 - 'a';
        int src_y = ch2 - '1';
        int dest_x = ch3 - 'a';
        int dest_y = ch4 - '1';
        memset(visited, 0, sizeof(visited));
        queue<Pair> q;
        q.emplace(Pair(Point(src_x, src_y), 0));
        int min_step = -1;
        while (!q.empty()) {
            Pair top = q.front();
            q.pop();
            int x = top.first.first;
            int y = top.first.second;
            int step = top.second;
            visited[x][y] = true;
            if (x == dest_x && y == dest_y) {
                min_step = step;
                break;
            }
            for (int direction = 0; direction < 8; ++direction) {
                int next_x = x + DIRECTIONS_X[direction];
                int next_y = y + DIRECTIONS_Y[direction];
                if (next_x >= 0 && next_x < 8 && next_y >= 0 && next_y < 8 && !visited[next_x][next_y]) {
                    q.emplace(Pair(Point(next_x, next_y), step + 1));
                }
            }
        }
        cout << "To get from " << ch1 << ch2 << " to " << ch3 << ch4 << " takes " << min_step << " knight moves." << endl;
    }

    return 0;
}
