//https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
      unordered_set<int> from;      
      unordered_set<int> to;

      for(vector<int> pair: edges) {
        to.insert(pair[1]);
        if(from.find(pair[1]) != from.end()) from.erase(pair[1]);

        if(to.find(pair[0]) == to.end()) from.insert(pair[0]);
      }
      vector<int> starts;
      for (const auto& element : from) {
        starts.push_back((int)element);
      }  
      return starts;
    }
};
