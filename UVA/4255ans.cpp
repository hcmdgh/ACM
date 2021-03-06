#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10 + 5;

int n, G[maxn][maxn];
int c[maxn];
vector<int> topo;

bool dfs(int u){
  c[u] = -1;
  for(int v = 0; v <= n; v++) if(G[u][v]) {
    if(c[v]<0) return false;
    else if(!c[v]) dfs(v);
  }
  c[u] = 1; topo.push_back(u);
  return true;
}

bool toposort(){
  topo.clear();
  memset(c, 0, sizeof(c));
  for(int u = 0; u <= n; u++) if(!c[u])
    if(!dfs(u)) return false;
  reverse(topo.begin(), topo.end());
  return true;
}


int pa[maxn];
int findset(int x) { return pa[x] != x ? pa[x] = findset(pa[x]) : x; }

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif // DEBUG
  int T;
  scanf("%d", &T);
  while(T--) {
    char input[100], S[11][11];
    scanf("%d%s", &n, input);
    int idx = 0;
    for(int i = 0; i <= n; i++) pa[i] = i;
    for(int i = 1; i <= n; i++)
      for(int j = i; j <= n; j++) {
        S[i][j] = input[idx++];
        if(S[i][j] == '0') pa[j] = i-1;
      }


    memset(G, 0, sizeof(G));
    for(int i = 1; i <= n; i++)
      for(int j = i; j <= n; j++) {
        if(S[i][j] == '-') G[findset(j)][findset(i-1)] = 1;
        if(S[i][j] == '+') G[findset(i-1)][findset(j)] = 1;
      }
    toposort();
    int sum[maxn], cur = 0;
    for(int i = 0; i <= n; i++) sum[topo[i]] = cur++;
    for(int i = 1; i <= n; i++) {
      sum[i] = sum[findset(i)];
      if(i > 1) printf(" ");
      printf("%d", sum[i] - sum[i-1]);
    }
    printf("\n");
  }
  return 0;
}
