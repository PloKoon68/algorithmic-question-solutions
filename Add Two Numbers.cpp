/*
QUESTİON:

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    struct ListNode* sum = new ListNode;
    struct ListNode* hold;
    hold = sum;
    int remainder = 0;

    while (l1 || l2 || remainder) {
        int val1 = 0, val2 = 0;
        if (l1)
            val1 = l1->val;
        if (l2)
            val2 = l2->val;
        
        
        sum->val = (val1 + val2 + remainder) % 10;
        remainder = (val1 + val2 + remainder) / 10;
    
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;

        if (l1 || l2 || remainder) {
            sum->next = new ListNode;
            sum = sum->next;
        }
        else
            break;
    }
        
    sum->next = NULL;
    return hold;
}
