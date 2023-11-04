#include <iostream>
#include <vector>
#include <queue>
// bipartite in this code
using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  vector<int>color(adj.size(), -1); // initialize color to -1 (unassigned)
  queue<int> q;
  for (int s = 0; s < adj.size(); s++) {
    if (color[s] == -1) { // not yet colored
      q.push(s);
      color[s] = 0; // assign color 0 to the starting of vertex
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) { 
          if (color[v] == -1) { // not yet colored
            q.push(v);
            color[v] = 1 - color[u]; // assign opposite color to v
          } else if (color[v] == color[u]) { // same color as u
            return 0; // not bipartite
          }
        }
      }
    }
  }
  return 1; // bipartite
}

int main() {
  int n,  m; 
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}

