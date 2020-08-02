class Solution {
public:
    /**
     * @param meeting: the meetings
     * @param value: the value
     * @return: calculate the max value
     */
    int maxValue(vector<vector<int>> &meeting, vector<int> &value) {
        vector<vector<int>>meetings;
        set<int>endTimes({0});
        for (int i=0; i<meeting.size(); i++)
        {
            meetings.push_back({meeting[i][1],meeting[i][0],value[i]});
            endTimes.insert(meeting[i][1]);
        }
        sort(meetings.begin(), meetings.end());
        
        unordered_map<int,int>time2val;
        time2val[0] = 0;
        int curVal = 0;
        
        for (int i=0; i<meetings.size(); i++)
        {
            int end = meetings[i][0];
            int start = meetings[i][1];
            int val = meetings[i][2];

            auto iter = endTimes.upper_bound(start);
            iter = prev(iter,1);
            int lastEnd = *iter;
            time2val[end] = max(curVal, time2val[lastEnd]+val);
            
            curVal = time2val[end];
        }
        
        return curVal;
    }
};
