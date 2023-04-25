//https://leetcode.com/problems/smallest-number-in-infinite-set/description/

class SmallestInfiniteSet {
public:
    struct Compare {
      bool operator()(const int& a, const int& b) {
          return a > b;
      }
    };
    priority_queue<int, vector<int>, Compare> added;
    unordered_set<int> set;
    int cur = 1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
      if(added.size()) {
        int num = added.top();
        added.pop();
        set.erase(num);
        return num;
      }

      return cur++;
    }
    
    void addBack(int num) {
      if(num < cur && !set.count(num)) {
        added.push(num);
        set.insert(num);
      }
    }
};
