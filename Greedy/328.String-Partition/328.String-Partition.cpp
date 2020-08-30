class Solution {
public:
    /**
     * @param s: a string
     * @return:  an array containing the length of each part
     */
    vector<int> splitString(string &s) {
        vector<int>start(26,-1);
        vector<int>end(26,-1);
        for (int i=0; i<s.size(); i++) 
            if (start[s[i]-'A']==-1) start[s[i]-'A'] = i;
        for (int i=s.size()-1; i>=0; i--) 
            if (end[s[i]-'A']==-1) end[s[i]-'A'] = i;
        
        vector<vector<int>>intervals;
        for (int i=0; i<26; i++)
        {
            if (start[i]==-1) continue;
            int left = start[i], right = end[i];
            bool valid = true;
            for (int k=left; k<=right; k++)
            {
                if (start[s[k]-'A']==-1) continue;
                if (start[s[k]-'A'] < left)
                {
                    valid = false;
                    break;
                }
                right = max(right, end[s[k]-'A']);
            }
            if (valid) intervals.push_back({left, right});
        }
        
        sort(intervals.begin(), intervals.end()); 
        
        vector<int>rets;
        for (int i=0; i<intervals.size(); i++)
        {
            int flag = 1;
            for (int j=0; j<i; j++)
            {                
                if (intervals[i][0]>intervals[j][0] && intervals[i][1]<intervals[j][1])                
                {
                    flag = 0;                
                    break;
                }
            }
            if (flag)
                rets.push_back(intervals[i][1]-intervals[i][0]+1);
        }
        
      return rets;
    }
};
