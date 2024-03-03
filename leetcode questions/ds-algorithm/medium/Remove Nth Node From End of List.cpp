//question:         https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03
//my solution       https://leetcode.com/problems/remove-nth-node-from-end-of-list/solutions/4816361/beats-100-c/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0;
        ListNode* next = head;
        ListNode* prev = new ListNode(INT_MIN);
        prev->next = head;

        while (next && i++ < n) next = next->next;
        
        while (next) {
            next = next->next;
            prev = prev->next;
        }
        if (prev->val == INT_MIN) {
            head = head->next;
            return head;
        }

        prev->next = prev->next->next;
        return head;
    }
};
