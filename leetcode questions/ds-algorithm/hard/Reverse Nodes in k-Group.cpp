//https://leetcode.com/problems/reverse-nodes-in-k-group/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* connect = new ListNode;
      ListNode* current = head;
      ListNode* start;
      stack<ListNode*> reverseNodes;
      int i;
      for(int j = 0; j < k- 1; j++)
        head = head->next;
      
      while(true) {
        i = 0;

        start = current;
        while(i++ < k) {
          if(!current) {
            connect->next = start;
            return head;
          }
          reverseNodes.push(current);
          current = current->next;
        }
        
        
        while(reverseNodes.size()) {
          connect->next = reverseNodes.top();
          connect = connect->next;
          reverseNodes.pop();
        }        
       }   
      return head;
    }
};
