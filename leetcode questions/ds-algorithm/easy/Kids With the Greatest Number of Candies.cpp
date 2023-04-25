//https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/


class Solution {
public:
    
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> result(candies.size());
    int max = -1;
    for(int i: candies)
      if(max < i)
        max = i;

    for(int i = 0;i < candies.size(); i++)
        result[i] = (candies[i] + extraCandies >= max);
    return result;
  }
};
