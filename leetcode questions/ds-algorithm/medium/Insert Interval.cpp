//question:       https://leetcode.com/problems/insert-interval/description/
//my solution:    https://leetcode.com/problems/insert-interval/solutions/4889211/binary-search-c/


class Solution {
public:
    int bs(vector<vector<int>>& intervals, vector<int>& newInterval, int i) {
        int l = 0, u = intervals.size() - 1, m, st = newInterval[i];
        while (l <= u) {
            m = (l + u) / 2;

            //check if the point is valid, if so return
            if (st > intervals[m][i]) {
                if (m == intervals.size() - 1 || st < intervals[m + 1][i]) return m + 1;
                else l = m + 1;
            }
            else {
                if (m == 0 || st > intervals[m - 1][i]) return m;
                else u = m - 1;
            }

        }

        return -1;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if (!intervals.size()) return vector<vector<int>> {newInterval};
    int n = intervals.size();

    int startInd = bs(intervals, newInterval, 0);
    int endInd = bs(intervals, newInterval, 1) -1;
    endInd = (endInd < n-1 && intervals[endInd + 1][1] == newInterval[1]) ? endInd + 1 : endInd;
    int s = newInterval[0], e = newInterval[1];
    if (startInd > 0 && newInterval[0] <= intervals[startInd - 1][1]) {
        s = intervals[startInd - 1][0];
        startInd--;
    }
    if (endInd < n-1 && newInterval[1] >= intervals[endInd + 1][0]) {
        e = intervals[endInd + 1][1];
        endInd++;
    }
    

    if(startInd <= endInd)
        intervals.erase(intervals.begin() + startInd, intervals.begin() + endInd + 1);
    intervals.insert(intervals.begin() + startInd, vector<int> {s, e});

    return intervals;
}
};
