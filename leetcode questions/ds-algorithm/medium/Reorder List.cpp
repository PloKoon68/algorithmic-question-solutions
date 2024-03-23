//question:      https://leetcode.com/problems/reorder-list/description/
//my solution:   https://leetcode.com/problems/reorder-list/


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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        stack<ListNode*> st;
        ListNode* first = head;
        ListNode* second = head->next;
        while(second && second->next) {
            first = first->next;
            second = second->next->next;
        }
        first = first->next;
        while(first) {
            st.push(first);
            first = first->next;
        }

        first = head;
        second;
        while(!st.empty()) {
            second = first->next;
            first->next = st.top();
            st.top()->next = second;
            st.pop();
            first = second;
        }
        first->next = nullptr;
    }
};
