class Solution {
public:
    /**
     * return the index of the winner with the highest probability of winning
     * @param probability double浮点型vector<vector<>> the winning probability of 16 teams in pairs
     * @return int整型
     */
    int findWinner(vector<vector<double> >& probability) 
    {
        double dp[16][17][16];
        for (int i=0; i<16; i++)
            for (int j=0; j<=16; j++)
                for (int k=0; k<16; k++)
                    dp[i][j][k] = 0;
        
        for (int i=0; i<16; i++)
            dp[i][1][0] = 1;
        
        for (int len = 2; len<=16; len*=2)
        {
            for (int i=0; i<16; i+=len)
            {                
                for (int x=0; x<len/2; x++)
                    for (int y=len/2; y<len; y++)
                        dp[i][len][x] += dp[i][len/2][x] * dp[i+len/2][len/2][y-len/2] * probability[i+x][i+y];
                for (int x=len/2; x<len; x++)
                    for (int y=0; y<len/2; y++)
                        dp[i][len][x] += dp[i][len/2][y] * dp[i+len/2][len/2][x-len/2] * probability[i+x][i+y];
            }
        }
        double pro = 0;
        int team;
        for (int i=0; i<16; i++)
            if (dp[0][16][i] > pro)
            {
                pro = dp[0][16][i];
                team = i;
            }
        return team;
    }
};
