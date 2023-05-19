//https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
  bool isBipartite(vector<vector<int>> &graph) {

    vector<int> colors(graph.size(), -1);
    vector<int> visited(graph.size(), 0);

    for(int i = 0; i < visited.size(); i++){
      if(!graph[i].size())
        continue;
    else if(!visited[i])
      if(!traverse(colors, graph, -1, i, visited)) return false;
    }

    return true;
  }
  bool traverse(vector<int> &colors, vector<vector<int>> &graph, int before,
                int current, vector<int> visited) {

    for (int edge : graph[current]) {
      if (edge == before)
        continue;
      else if (colors[edge] == -1) {
        colors[edge] = !colors[current];
        if (!traverse(colors, graph, current, edge, visited))
          return false;
      } else if (colors[current] == colors[edge])
        return false;
    }
    visited[current]++;
    return true;
  }
};
