class Solution {
public:
    /**
     * @param song: an array represent song'time
     * @param M: an integer represent sont time limit
     * @return: return the longest time for song
     */
    int LongestSongTime(vector<int> &song, int M) 
    {
        sort(song.begin(), song.end());
        int last = song.back();
        song.pop_back();
        
        vector<int>dp(M+1,0);
        dp[0] = 1;
        for (int i=0; i<song.size(); i++)
        {
            auto dp2 = dp;
            for (int t=1; t<M; t++)
            {
                if (t-song[i]>=0 && dp2[t-song[i]]==1)
                   dp[t] = 1;
            }
        }
        
        int ret = 0;
        for (int t=0; t<M; t++)
            if (dp[t]==1)
                ret = t;
            
        return ret+last;
    }
};
