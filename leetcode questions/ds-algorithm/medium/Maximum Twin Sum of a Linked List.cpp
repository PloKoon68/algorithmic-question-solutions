//https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/


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
    int pairSum(ListNode* head) {
      ListNode* slow = head;      
      ListNode* fast = head->next;
      stack<int> nums;
      int max = head->val, sum;
      
      while(true) {
        nums.push(slow->val);  
        slow = slow->next;
        if(!fast->next)
          break;
        fast = fast->next->next;
      }
      while(slow) {
        sum = slow->val + nums.top();
        max = (max < sum)? sum: max;
        slow = slow->next;
        nums.pop();
      }
      return max;
    }
};
