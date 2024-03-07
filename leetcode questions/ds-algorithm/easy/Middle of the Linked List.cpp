//question:      https://leetcode.com/problems/middle-of-the-linked-list/?envType=daily-question&envId=2024-03-07
//my solution:   https://leetcode.com/problems/middle-of-the-linked-list/solutions/4838535/beats-100-c/




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
    ListNode* middleNode(ListNode* head) {
        ListNode* prev = new ListNode(INT_MIN);
        ListNode* next = prev;
        prev->next = head;

        while (next) {
            prev = prev->next;
            next = next->next? next->next->next: next->next;
        }

        return prev;

    }
};

