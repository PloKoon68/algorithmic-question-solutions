//https://leetcode.com/problems/meeting-rooms-iii/?envType=daily-question&envId=2024-02-18


class Solution {
public: 
    struct ComparePairs {
        bool operator()(const vector<long>& a, const vector<long>& b) const {
            if (a[1] != b[1]) {
                // Sort by the second element in increasing order
                return a[1] > b[1]; // Greater means lower value on top
            }
            else {
                // If second elements are equal, sort by the first element in increasing order
                return a[0] > b[0]; // Greater means lower value on top
            }
        }
    };

    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long> counts(n, 1);

        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
            };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> start(cmp);
        //generate the start queue
        for (const auto& inner_vec : meetings) start.push(inner_vec);

        //fill finish with n elements
        priority_queue<vector<long>, vector<vector<long>>, ComparePairs> finish;

        
        int i = 0;
        while (i < n) finish.push({ i++, 0 });

        
        while (!start.empty()) {
            //if the next ones start is bigger than the ones finish
            stack<int> rooms;
            int nextStart = start.top()[0];
            while (!finish.empty() && nextStart > finish.top()[1]) {
                rooms.push(finish.top()[0]);
                finish.pop();
            }
            while (!rooms.empty()) {
                finish.push({rooms.top(), nextStart});
                rooms.pop();
            }

                                      //room number
            vector<long> newMeeting = { finish.top()[0], finish.top()[1] + (start.top()[1] - start.top()[0])};
            counts[finish.top()[0]]++;

            start.pop();
            finish.pop();
            finish.push(newMeeting);
        }
        
        long max = counts[0];
        int ind = 0;
        for (int i = 1; i < n; i++) {
            if (max < counts[i]) {
                max = counts[i];
                ind = i;
            }
        }

        return ind;
    }
};
