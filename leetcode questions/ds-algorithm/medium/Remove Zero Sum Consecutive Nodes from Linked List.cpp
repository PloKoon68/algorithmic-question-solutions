//https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/?envType=daily-question&envId=2024-03-12


class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> sums;
        sums[0] = nullptr;
        ListNode* node = head;

        int sum = 0;
        while (node) {
            sum += node->val;

            //delete
            if (sums.find(sum) != sums.end()) {

                ListNode* toDelete = (!sum)? head:sums[sum]->next;
                while (toDelete != node) {
                    sum += toDelete->val;
                    sums.erase(sum);
                    toDelete = toDelete->next;
                }
                sum += node->val;

                if (!sum) head = node->next;
                else sums[sum]->next = node->next;
            }   
            //add
            else sums[sum] = node;
            node = node->next;
        }
        return head;
    }
};
