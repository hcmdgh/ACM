#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int src_x, src_y, dest_x, dest_y;
char src_direction;
bool layout[10][10][4][4];
bool visited[10][10][4];

const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;
const int DIRECTIONS_X[4] = {-1, 1, 0, 0};
const int DIRECTIONS_Y[4] = {0, 0, -1, 1};

struct State {
    int x, y, face, last;

    State(int x, int y, int face, int last) : x(x), y(y), face(face), last(last) {}
};

int main() {
    ios::sync_with_stdio(false);
    string name;
    while ((cin >> name) && name != "END") {
        memset(layout, 0, sizeof(layout));
        cin >> src_x >> src_y >> src_direction >> dest_x >> dest_y;
        int x, y;
        while ((cin >> x) && x > 0) {
            cin >> y;
            string directions;
            while ((cin >> directions) && directions != "*") {
                char face = directions[0];
                for (int i = 1; i < directions.length(); ++i) {
                    char ch = directions[i];
                    if (face == 'N') {
                        if (ch == 'L') {
                            layout[x][y][UP][LEFT] = true;
                        } else if (ch == 'R') {
                            layout[x][y][UP][RIGHT] = true;
                        } else /*if (ch == 'F')*/ {
                            layout[x][y][UP][UP] = true;
                        }
                    } else if (face == 'S') {
                        if (ch == 'L') {
                            layout[x][y][DOWN][RIGHT] = true;
                        } else if (ch == 'R') {
                            layout[x][y][DOWN][LEFT] = true;
                        } else /*if (ch == 'F')*/ {
                            layout[x][y][DOWN][DOWN] = true;
                        }
                    } else if (face == 'W') {
                        if (ch == 'L') {
                            layout[x][y][LEFT][DOWN] = true;
                        } else if (ch == 'R') {
                            layout[x][y][LEFT][UP] = true;
                        } else /*if (ch == 'F')*/ {
                            layout[x][y][LEFT][LEFT] = true;
                        }
                    } else /*if (face == 'E')*/ {
                        if (ch == 'L') {
                            layout[x][y][RIGHT][UP] = true;
                        } else if (ch == 'R') {
                            layout[x][y][RIGHT][DOWN] = true;
                        } else /*if (ch == 'F')*/ {
                            layout[x][y][RIGHT][RIGHT] = true;
                        }
                    }
                }
            }
        }

        vector<State> states;
        int face;
        if (src_direction == 'N')
            face = UP;
        else if (src_direction == 'S')
            face = DOWN;
        else if (src_direction == 'W')
            face = LEFT;
        else
            face = RIGHT;
        states.emplace_back(State(src_x + DIRECTIONS_X[face], src_y + DIRECTIONS_Y[face], face, -1));
        int begin_pos = 0, end_pos = 0;
        int dest_idx = -1;
        memset(visited, 0, sizeof(visited));
        visited[src_x + DIRECTIONS_X[face]][src_y + DIRECTIONS_Y[face]][face] = true;
        while (begin_pos <= end_pos && dest_idx == -1) {
            for (int i = begin_pos; i <= end_pos; ++i) {
                face = states[i].face;
                x = states[i].x;
                y = states[i].y;
                if (x == dest_x && y == dest_y) {
                    dest_idx = i;
                    break;
                }
                for (int direction = 0; direction < 4; ++direction) {
                    if (layout[x][y][face][direction]) {
                        int next_x = x + DIRECTIONS_X[direction];
                        int next_y = y + DIRECTIONS_Y[direction];
                        if (next_x >= 1 && next_x <= 9 && next_y >= 1 && next_y <= 9 && !visited[next_x][next_y][direction]) {
                            visited[next_x][next_y][direction] = true;
                            states.emplace_back(State(next_x, next_y, direction, i));
                        }
                    }
                }
            }
            begin_pos = end_pos + 1;
            end_pos = states.size() - 1;
        }
        cout << name << endl;
        cout << "  ";
        if (dest_idx == -1) {
            cout << "No Solution Possible" << endl;
        } else {
            vector<pair<int, int>> ans;
            State& dest = states[dest_idx];
            ans.emplace_back(pair<int, int>(dest.x, dest.y));
            int idx = dest.last;
            while (idx > -1) {
                ans.emplace_back(pair<int, int>(states[idx].x, states[idx].y));
                idx = states[idx].last;
            }
            ans.emplace_back(pair<int, int>(src_x, src_y));
            int ans_size = ans.size();
            for (int i = 0; i < ans_size; ++i) {
                cout << "(" << ans[ans_size - 1 - i].first << "," << ans[ans_size - 1 - i].second << ")";
                if (i == ans_size - 1)
                    cout << endl;
                else if ((i + 1) % 10 == 0)
                    cout << endl << "  ";
                else
                    cout << ' ';
            }
        }
    }

    return 0;
}
