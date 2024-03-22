//question:     https://leetcode.com/problems/merge-k-sorted-lists/
//my solution:  https://leetcode.com/problems/merge-k-sorted-lists/solutions/4911850/c-priority-queue-simple/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = []( int a, int b ) { return a > b; };
        priority_queue< int , vector<int>, decltype( comp ) > pq( comp );

        for(int i = 0; i < lists.size(); i++) {
            ListNode* ll = lists[i];
            while(ll) {
                pq.push(ll->val);
                ll = ll->next;
            }
        }

        if(pq.empty()) return nullptr;

        ListNode* node = new ListNode(pq.top());
        ListNode* head = node;
        pq.pop();

        while(!pq.empty()) {
            node->next = new ListNode(pq.top());
            node = node->next;
            pq.pop();
        }
        return head;
    }
};
