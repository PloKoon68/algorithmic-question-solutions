//https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/
//https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/solutions/5422004/c-beats-92-66/


class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return vector<int> {-1, -1};
        int firstInd = 0, lastInd = 0, minDist = INT_MAX, prevVal = head->val, currentInd = 1;

        ListNode* current = head->next;
        while (current->next) {
            int curVal = current->val, nextVal = current->next->val;
            //check if critical point
            if ((curVal < prevVal && curVal < nextVal) || (curVal > prevVal && curVal > nextVal)) {
                if (!firstInd) firstInd = currentInd;  //get the first critical points index
                else if ((currentInd - lastInd) < minDist)  //check if minDist found
                    minDist = currentInd - lastInd;
                lastInd = currentInd;
            }
            currentInd++;
            prevVal = curVal;
            current = current->next;
        }

        vector<int> result = { -1, -1 };
        if (firstInd != lastInd) {
            result[0] = minDist;
            result[1] = lastInd - firstInd;
        }
        return result;
    }
};
