//https://leetcode.com/problems/merge-in-between-linked-lists/description/?envType=daily-question&envId=2024-03-20

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if(!list2) return list1;

        ListNode* node1 = list1;
        ListNode* node2;
        int i = 0;
        while(++i < a) node1 = node1->next;
        node2 = node1;
        i-= 2;
        while(++i <= b) node1 = node1->next;
        node2->next = list2;
        while(node2->next) node2 = node2->next;
        node2->next = node1;
        return list1;
    }
};
