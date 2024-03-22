//question:      https://leetcode.com/problems/palindrome-linked-list/description/
//my solution:   https://leetcode.com/problems/palindrome-linked-list/solutions/4911647/c-stack/


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
    bool isPalindrome(ListNode* head) {
        ListNode* node = head;
        int count = 0;
        while(node) {
            count++;
            node = node->next;
        }

        stack<int> st;
        node = head;
        int i = 0, half = count / 2;
        while(i < half) {
            st.push(node->val);
            node = node->next;
            i++;
        }
        if(count % 2) 
            node = node->next;
        while(node) {
            if(st.top() != node->val) return false;
            st.pop();
            node = node->next;
        }
        return true;
    }
};
