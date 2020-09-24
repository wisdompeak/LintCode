class Solution {
public:
    /**
     * @param color: the color of each piece
     * @param number: the number of each piece
     * @return: the minimum number of operations
     */
    long Red[2002][2];
    long Blue[2002][2];
    long dp[2002][2002];
    long r2b[2002][2002];
    long b2r[2002][2002];
        
    int RedBlackChess(string &color, vector<int> &number) 
    {
        int n = color.size()/2;
        
        color = "#" + color;
        number.insert(number.begin(), 0);
        
        for (int i=1; i<=2*n; i++)
        {
            int val = number[i];
            
            if (color[i]=='R')
            {
                Red[val][0] = 0;
                Red[val][1] = 0;
                
                for (int k=1; k<i; k++)
                {
                   if (color[k]=='R' && number[k]>val) 
                        Red[val][0]++;
                   else if (color[k]=='B')
                   {
                        r2b[val][number[k]] = 1;
                        Red[val][1]++;   
                   }
                    
                }
            }
            else if (color[i]=='B')
            {
                Blue[val][0] = 0;
                Blue[val][1] = 0;
                
                for (int k=1; k<i; k++)
                {
                   if (color[k]=='B' && number[k]>val) 
                    Blue[val][1]++;
                   else if (color[k]=='R')
                   {
                       Blue[val][0]++;
                       b2r[val][number[k]] = 1;
                   }
                    
                }
            }
        }
        
        for (int val=1; val<=n; val++)
        {
            for (int i=1; i<=n; i++)
            {
                b2r[val][i] = b2r[val][i-1]+b2r[val][i];
                r2b[val][i] = r2b[val][i-1]+r2b[val][i];
            }
        }
        
        for (int total=1; total<=2*n; total++)
            for (int r=0; r<=min(n,total); r++)
            {
                int b = total - r;
                if (b>n) continue;
                dp[r][b] = INT_MAX/2;
                
                if (r>=1)
                {
                    dp[r][b] = min(dp[r][b], dp[r-1][b] + Red[r][0] + Red[r][1] - r2b[r][b]);
                }
                if (b>=1)
                {
                    dp[r][b] = min(dp[r][b], dp[r][b-1] + Blue[b][1] + Blue[b][0] - b2r[b][r]);
                }
            }
        return dp[n][n];
    }
};
