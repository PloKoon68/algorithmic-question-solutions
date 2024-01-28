//https://leetcode.com/problems/combinations/description/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> combination(k, 0);
        process(combinations, combination, &n, &k, 0, 0);

    return combinations;    
    }

    void process(vector<vector<int>> &combinations, vector<int>& combination, int* n, int* k, int level, int prev) {
        if(level == *k) {
            combinations.push_back(combination);
            return;
        }

        for(int i = prev + 1; i <= *n - (*k - level - 1); i++) {
            combination[level] = i;
            process(combinations, combination, n, k, level + 1, i);
        }
    }
};
