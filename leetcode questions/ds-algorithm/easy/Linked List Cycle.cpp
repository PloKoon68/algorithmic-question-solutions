//https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2024-03-06

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       unordered_set<ListNode*> set;
       ListNode* node = head;
       while(node) {
           if(set.find(node) != set.end()) return true;
            set.insert(node);
           node = node->next;
       }  

       return false;
    }
};
