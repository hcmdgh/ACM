#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

typedef long long ll;
int N, M, K;

struct Edge {
    int begin, end, weight;

    bool operator<(const Edge &other) {
        return weight < other.weight;
    }
} edges[200000];

map<int, int> vertex2vertex;
ll dis[800][800];
ll distances[80000];

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].begin >> edges[i].end >> edges[i].weight;
    }

    sort(edges, edges + M);
    int edge_count = min(M, K);
    int vertex_count = 0;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 0; i < edge_count; ++i) {
        for (int v : {edges[i].begin, edges[i].end}) {
            if (vertex2vertex.count(v) == 0) {
                vertex2vertex[v] = vertex_count;
                ++vertex_count;
            }
        }
        int begin = vertex2vertex[edges[i].begin], end = vertex2vertex[edges[i].end];
        dis[begin][end] = dis[end][begin] = edges[i].weight;
    }

    for (int k = 0; k < vertex_count; ++k) {
        for (int i = 0; i < vertex_count; ++i) {
            for (int j = 0; j < vertex_count; ++j) {
                if (dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    int distances_count = 0;
    for (int i = 1; i < vertex_count; ++i) {
        for (int j = 0; j < i; ++j) {
            distances[distances_count] = dis[i][j];
            ++distances_count;
        }
    }
    sort(distances, distances + distances_count);

    cout << distances[K - 1] << endl;

    return 0;
}