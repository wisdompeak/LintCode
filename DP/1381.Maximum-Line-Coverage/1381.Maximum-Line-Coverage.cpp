/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: The intervals
     * @param k: The k
     * @return: The answer
     */
    static bool cmp(Interval &a, Interval &b) {
        if(a.start != b.start) {
            return a.start < b.start;
        }
        return a.end < b.end;
    }
    
    int maximumLineCoverage(vector<Interval> &intervals, int k) {
        sort(intervals.begin(), intervals.end(), cmp);

        int MaxPos = 0;
        for(auto it: intervals) {
            MaxPos = max(MaxPos, it.end);
        }
                
        vector<vector<int>> dp(MaxPos+1, vector<int>(k+2));

        int far = 0;
        int index = 0;
        for(int i = 0; i < MaxPos; i++) 
        {
            while(index < intervals.size() && intervals[index].start <= i + 1) 
            {
                far = max(far, intervals[index].end);
                index++;
            }
            for(int j = 0; j <= k; j++) 
            {
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);//不取
                if(far <= MaxPos) {
                    dp[far][j + 1] = max(dp[i][j] + far-i, dp[far][j + 1]);//取
                }
            }
        }
        return dp[MaxPos][k];
    }
};
