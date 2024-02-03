//https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = INT32_MIN;
        int* left = &height[0];
        int* right = &height[height.size() - 1];
        int tresh;

        while (left != right) {
            tresh = min(*left, *right);
            int area = tresh * (right - left);
            if (area > max) max = area;
            if (*right <= *left)
                while (left != right && *right <= tresh)right--;
            else 
                while (left != right && *left <= tresh) left++;
        }

        return max;
    }
};
