//https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
      ListNode* nextStep = head;
      ListNode* current;
      ListNode* next;
      if(!head || !head->next) return head;
      head = head->next;
      while(nextStep && nextStep->next) {
        current = nextStep;
        next = current->next;
        nextStep = next->next;
        current->next = (nextStep)? (nextStep->next)? nextStep->next: nextStep: nextStep;
        next->next = current;
      }
      return head;
     } 
};
