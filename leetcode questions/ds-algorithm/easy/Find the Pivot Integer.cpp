//https://leetcode.com/problems/find-the-pivot-integer/description/?envType=daily-question&envId=2024-03-13


class Solution {
public:
    int pivotInteger(int n) {
        float result = sqrt((n * n + n) / 2);
        return result - (int)result == 0? result: -1;
    }
};
