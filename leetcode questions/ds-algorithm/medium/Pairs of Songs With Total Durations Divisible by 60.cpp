class Solution {
public:
  int numPairsDivisibleBy60(vector<int> &time) {
    unordered_map<int, pair<int, int>> map;
    long long count = 0, s = 0, t = 0;

    for (int i : time) {
      if (i%60 == 0)
        s++;
      else if (i%60 == 30)
        t++;
      else if (map.count(60 - i % 60)>0)
        map[60 - i % 60].second++;
      else 
        map[i%60].first++;
    }

    count += s * (s - 1) / 2;
    count += t * (t - 1) / 2;
    
    for (const auto &pair : map) {
      int f = pair.second.first;
      int s = pair.second.second;
      count += f * s;
    }
    return count;
  }
};

