//question:     https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/
// my solution: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/solutions/5869227/o-n-map-c/

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int teamSum = 0;
        for(int s: skill)
            teamSum += s;
        teamSum = teamSum / (skill.size() / 2);   //calculate the teamSum value where each pair of teams sum should be equal to 

        long long chemistry = 0;    //final total chemistry will be calculated
        unordered_map<int, int> map;   //map to check if current skill's team member was already assigned to its team
        for(int s: skill) {
            if(map[s]) {     //if the skill's team member was added to a team
                map[s]--;    //delete them from map
                chemistry += s * (teamSum - s);  // add the multiplication of the skills of two team members
            }
            else {
                map[teamSum - s]++;    //if the skill is found before it's team member, add it's team member to the map
            } 
        }

        for (auto &entry : map) //check if anyone left without a team member
            if (entry.second != 0) return -1;  
        
        return chemistry;
    }
};
