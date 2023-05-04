
class Solution {
public:
  struct ll {
    char val;
    struct ll* next = nullptr;
  };
  struct ll *root;
  struct ll *last;

  int r = 0;
  int d = 0;

  //stack olmazsa set
  stack<char> senateEliminate;

  void circularLL(string s) {
    struct ll *itr = new ll;
    root = itr->next;

    for (int i = 0; i < s.length(); i++) {
      itr->next = new ll;
      itr = itr->next;
      itr->val = s[i];

      if(i == 0) root = itr;
      (s[i] == 'R') ? r++ : d++;
    }

    itr->next = root;
    last = itr;
  }

  
  string predictPartyVictory(string senate) {
        circularLL(senate);
    struct ll *itr = last;
      while(true) {
        if(!d)
          return "Radiant";
        if(!r)
          return "Dire";

        if(senateEliminate.size()) {
          char deleteChar = senateEliminate.top();
          if(deleteChar == itr->next->val) {
            struct ll *t = itr->next;
            itr->next = itr->next->next;
            delete t;
            (deleteChar == 'R')? r--: d--;
            senateEliminate.pop();
            
          }
          else {
            senateEliminate.push(((deleteChar == 'R')? 'R': 'D'));
            itr = itr->next;
          }
          continue;
        }
        senateEliminate.push(((itr->next->val == 'R')? 'D': 'R'));
        itr = itr->next;
        
      } 
      return "sf";
    }

    
};
