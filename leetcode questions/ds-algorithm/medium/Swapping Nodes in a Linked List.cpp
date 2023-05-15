//https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

class Solution {
public:
    ListNode* n1;
    ListNode* n2;
    int n;

    ListNode* swapNodes(ListNode* head, int k) {
      traverse(head, 0, k);
      
      int temp = n1->val;
      n1->val = n2->val;
      n2->val = temp;
      return  head;
    }
    void traverse(ListNode* head, int current, int k) {
      if(!head) {
        n = current;
        return;
      }

      if(current == k-1)
        n1 = head;
      
      traverse(head->next, current + 1, k);
    
      if(current == n - k) 
        n2 = head;

    }
};
