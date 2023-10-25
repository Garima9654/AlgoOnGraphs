#include <iostream>
#include <vector>

using std::vector;
//updated
int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  int n = adj.size();
  vector<int> dist(n, 0);
  for (int i = 0; i < n - 1; ++i) {
    for (int u = 0; u < n; ++u) {
      int m = adj[u].size();
      for (int j = 0; j < m; ++j) {
        int v = adj[u][j];
        int weight = cost[u][j];
        if (dist[v] > dist[u] + weight) {
          dist[v] = dist[u] + weight;
        }
      }
    }
  }
  for (int u = 0; u < n; ++u) {
    int m = adj[u].size();
    for (int j = 0; j < m; ++j) {
      int v = adj[u][j];
      int weight = cost[u][j];
      if (dist[v] > dist[u] + weight) {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
  return 0;
}
