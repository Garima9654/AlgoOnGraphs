#include <iostream>
#include <vector>
#include <queue>
// bipartite
using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  vector<int> color(adj.size(), -1); // initialize color to -1 (unassigned)
  queue<int> q;
  for (int s = 0; s < adj.size(); s++) {
    if (color[s] == -1) { // not yet colored
      q.push(s);
      color[s] = 0; // assign color 0 to the starting vertex
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


