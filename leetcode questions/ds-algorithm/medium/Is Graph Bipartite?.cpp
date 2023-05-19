//https://leetcode.com/problems/is-graph-bipartite/

//my solution with BFS logic but using recursive func
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
      if (colors[edge] == -1) {
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


//another solution with BFS using queue
/*
class Solution {
public:
    bool isBipartite(vector<vector<int>>& gr) {
        int n = gr.size();
        vector<int> colour(n, 0);

        for(int node = 0; node < n; node++){
            if(colour[node] != 0) continue;

            queue<int> q;
            q.push(node);
            colour[node] = 1;

            while(!q.empty()){
                int cur = q.front();
                q.pop();

                for(int ne : gr[cur]){
                    if(colour[ne] == 0){
                        colour[ne] = -colour[cur];
                        q.push(ne);
                    }else if(colour[ne] != -colour[cur]){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
*/
