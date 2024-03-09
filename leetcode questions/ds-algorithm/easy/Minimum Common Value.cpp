//question:      https://leetcode.com/problems/minimum-common-value/description/
//my solution:   https://leetcode.com/problems/minimum-common-value/solutions/4847536/beats-95-98-c-two-pointer/


class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0, i2 = 0;

        while(i1 < nums1.size() && i2 < nums2.size()) {
            int n1 = nums1[i1], n2 = nums2[i2];
            if(n1 == n2) return n1;
            else if(n1 < n2) i1++;
            else i2++;
        }
        return -1;
    }
};
