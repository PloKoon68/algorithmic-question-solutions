// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/?envType=daily-question&envId=2025-02-07

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> labels;
        unordered_map<int, int> colorCounts;

        vector<int> distinctColors(queries.size(), 0);

        int i = 0, distinctColorsCounts = 0;
        for(vector<int> query: queries) {
            int label = query[0], newColor = query[1];
            int prevColor = labels[label];

            //if that label is already colored,
            if(prevColor) {
                if(!--colorCounts[prevColor]) //decrease prevColorCount and if became 0, decrease also distinctColorCounts
                    distinctColorsCounts--;

                if(!colorCounts[newColor]++)  //increase new colors count  and if it was 0 before, increase distinctColorCounts
                    distinctColorsCounts++;
            }
            else {
                if(!colorCounts[newColor]) distinctColorsCounts++; //if new color count was 0, increase distinctColorCounts
                colorCounts[newColor]++; //increase new colors count

            }

            labels[label] = newColor;    //change that labels color with new one
            distinctColors[i++] = distinctColorsCounts;
        }

        return distinctColors;        
    }
};
