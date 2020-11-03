### 962. Condition string

#### Description
```
给定一个由小写字母a-f组成的字符串，对其进行删除，使得删除后的字符串满足：

所有的a在c和e之前且所有的c在e之前，
所有的b在d和f之前且所有的d在f之前。

求删除后满足以上条件的串的最大长度
1<=len(s)<=3*10^​5
```

#### 分析：
```
本题要求ace这三种字符满足相对顺序，bdf这三种字符满足相对顺序。而这组字符之间的顺序没有任何影响。
所以我们将所有ace的字符拼接在一起，考虑最少删除多少，能使他们满足a<c<e的相对顺序？
同理，将所有的bdf的字符拼接在一起，考虑最少删除多少，能使他们满足b<d<f的相对顺序？

最少删除多少字符，使得剩下的字符保持递增，本质就是查找原字符中的最长递增子序列 longest increasing subsequence (LIS)

return LIS({ace}) + LIS({bdf});

你知道LIS的三种写法吗？

普通写法： o(N^2)

	令dp[i]表示强制以i为结尾的LIS的长度。遍历这个LIS的前一个元素j的位置：dp[i] = dp[j]+1;

    int LIS(vector<int>& nums)
    {
        int n = nums.size(); 
        vector<int>dp(n,1);
        int ret = 1;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<i; j++)
            {
                if (nums[j]<=nums[i])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }


 文艺写法：o(NlogN)

 	用数组维护一个递增的序列。
 	每次将新元素k替换掉数组里“第一个大于k的元素”。这样整个数组依然保持递增，但是“整体”的高度变矮了，更有利于延长LIS。

 	Eg 		1 2 5 7 3 4 5

 		 	1 2 5 7 M
 	=>3?	1 2 3 7 M 
 	=>4? 	1 2 3 4 M 
 	=>5?	1 2 3 4 5

 	int LIS(vector<int>& nums)
    {
    	int n = nums.size();
        vector<int>q(n, INT_MAX);
        for (int i=0; i<nums.size(); i++)
        {
        	auto iter = upper_bound(q.begin(),q.end(),nums[i]);
            *iter = nums[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (q[i] != INT_MAX)
                return i + 1;  
        }
        return 1;      
    }

  特殊写法：o(3N)

  	利用本题的特点：元素只有三种数值。令dp[i][k]表示前i个元素里、以k为结尾的LIS的长度。

    int LIS(vector<int>& nums)
    {
        int n = nums.size(); 
        auto dp = vector<vector<int>>(n, vector<int>(4,0));
        dp[0][nums[0]] = 1;
        
        for (int i=1; i<n; i++)
        {
            if (nums[i]==1)
            {
                dp[i][1] = dp[i-1][1] + 1;
                dp[i][2] = dp[i-1][2];
                dp[i][3] = dp[i-1][3];
            }
            else if (nums[i]==2)
            {
                dp[i][1] = dp[i-1][1];
                dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + 1;
                dp[i][3] = dp[i-1][3];
            }
            else if (nums[i]==3)
            {
                dp[i][1] = dp[i-1][1];
                dp[i][2] = dp[i-1][2];
                dp[i][3] = max(dp[i-1][1], max(dp[i-1][2], dp[i-1][3])) + 1;
            }
        }
        
        int ret = 1;
        for (int k=1; k<=3; k++)
            ret = max(ret, dp[n-1][k]);
        return ret;
    }
```
