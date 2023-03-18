//https://leetcode.com/problems/design-browser-history/description/


class BrowserHistory {
    
public:
   vector<string> history;
    int currentPage = -1;

    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currentPage = 0;
    }
    
    void visit(string url) {
    //erase further visited histories
        history.erase(history.begin() + currentPage + 1, history.end());
        history.push_back(url);
        currentPage = history.size() - 1;
      }
    
    string back(int steps) {
      currentPage = (steps > currentPage)? 0: currentPage - steps;      
      return history[currentPage];
    }
    
    string forward(int steps) {
      currentPage = (steps > (history.size() - currentPage-1))? history.size()-1: currentPage + steps;
      return history[currentPage];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
