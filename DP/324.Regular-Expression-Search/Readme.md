### 324.Regular-Expression-Search

对于这道题，我们来分几步走：

Step 1. 我们先来看一下 LC 10.Regular-Expression-Matching 的代码。这段代码用来判断正则表达式p能否恰好完整代表字符串s。
```cpp
    bool canMatch(string p, string s) 
    {
        int M = s.size();
        int N = p.size();
        s = "0"+s;
        p = "0"+p;
        auto dp = vector<vector<int>>(M+1,vector<int>(N+1,0));
        dp[0][0] = 1;
        for (int j=2; j<=N; j++)
        {
            if (p[j]=='*'||p[j]=='?') dp[0][j]=dp[0][j-2];
        }
    
           //  s: X X X X i
           //  p: Y Y Y j
             
        for (int j=1; j<=N; j++)
            for (int i=1; i<=M; i++)
            {
                if (isalpha(p[j])) 
                {
                    dp[i][j] = (s[i]==p[j] && dp[i-1][j-1]);
                }
                else if (p[j]=='.')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j]=='*')
                {
                    bool temp1 = dp[i][j-2];                                   // *的作用是“没有作用”
                    bool temp2 = dp[i-1][j] && (s[i]==p[j-1] || p[j-1]=='.');  // *的作用是使得s末尾至少有一个p[j-1]
                    dp[i][j] = temp1 || temp2;
                }
            }
        return dp[M][N];        
    }
```
Step 2. 现在我们考虑'?'和'+'的作用，完善上述的代码：
```cpp
    bool canMatch(string p, string s) 
    {
        // ...
    
           //  s: X X X X i
           //  p: Y Y Y j
             
        for (int j=1; j<=N; j++)
            for (int i=1; i<=M; i++)
            {
                // ... 
                if (p[j]=='*')
                {
                    bool temp1 = dp[i][j-2];                                   // *的作用是“没有作用”
                    bool temp2 = dp[i-1][j] && (s[i]==p[j-1] || p[j-1]=='.');  // *的作用是使得s末尾至少有一个p[j-1]
                    dp[i][j] = temp1 || temp2;
                }
                else if (p[j]=='?')
                {
                    bool temp1 = dp[i][j-2];      // ?的作用是“没有作用”
                    bool temp2 = dp[i][j-1];      // ?的作用是使得s末尾有一个p[j-1]
                    dp[i][j] = temp1 || temp2;
                }
                else if (p[j]=='+')
                {
                    bool temp1 = dp[i][j-1];                                      // +的作用是使得s末尾有一个p[j-1]
                    bool temp2 = dp[i-1][j] && (s[i]==p[j-1] || p[j-1]=='.');     // +的作用是使得s末尾至少一个p[j-1]
                    dp[i][j] = temp1 || temp2;
                }
            }
        return dp[M][N];        
    }
```
Step 3. 现在我们考虑，不要求p完整匹配s，而是判断p是否能匹配s或者s的前缀。改动如下：
```cpp
    bool canSearch(string p, string s) 
    {
        // ...
    
           //  s: X X X X i
           //  p: Y Y Y j
             
        for (int j=1; j<=N; j++)
            for (int i=1; i<=M; i++)
            {
                // ... 
                if (p[j]=='*')
                {
                    bool temp1 = dp[i][j-2];                                   // *的作用是“没有作用”
                    bool temp2 = dp[i-1][j] && (s[i]==p[j-1] || p[j-1]=='.');  // *的作用是使得s末尾至少有一个p[j-1]
                    dp[i][j] = temp1 || temp2;
                }
                else if (p[j]=='?')
                {
                    bool temp1 = dp[i][j-2];      // ?的作用是“没有作用”
                    bool temp2 = dp[i][j-1];      // ?的作用是使得s末尾有一个p[j-1]
                    dp[i][j] = temp1 || temp2;
                }
                else if (p[j]=='+')
                {
                    bool temp1 = dp[i][j-1];                                      // +的作用是使得s末尾有一个p[j-1]
                    bool temp2 = dp[i-1][j] && (s[i]==p[j-1] || p[j-1]=='.');     // +的作用是使得s末尾至少一个p[j-1]
                    dp[i][j] = temp1 || temp2;
                }
                
                if (j==N && dp[i][j]==true) return true; // 一旦发现完整的p能匹配部分的s，就返回true
            }
        return false;
    }
```
Step 4. 接下来我们考虑'$'的作用，同样判断p是否能匹配s或者s的前缀。改动如下：
```cpp
    bool canSearch(string p, string s) 
    {
        // ...
    
           //  s: X X X X i
           //  p: Y Y Y j
             
        for (int j=1; j<=N; j++)
            for (int i=1; i<=M; i++)
            {
                // ... 
                if (p[j]=='*')
                {
                    bool temp1 = dp[i][j-2];                                   // *的作用是“没有作用”
                    bool temp2 = dp[i-1][j] && (s[i]==p[j-1] || p[j-1]=='.');  // *的作用是使得s末尾至少有一个p[j-1]
                    dp[i][j] = temp1 || temp2;
                }
                else if (p[j]=='?')
                {
                    bool temp1 = dp[i][j-2];      // ?的作用是“没有作用”
                    bool temp2 = dp[i][j-1];      // ?的作用是使得s末尾有一个p[j-1]
                    dp[i][j] = temp1 || temp2;
                }
                else if (p[j]=='+')
                {
                    bool temp1 = dp[i][j-1];                                      // +的作用是使得s末尾有一个p[j-1]
                    bool temp2 = dp[i-1][j] && (s[i]==p[j-1] || p[j-1]=='.');     // +的作用是使得s末尾至少一个p[j-1]
                    dp[i][j] = temp1 || temp2;
                }
                else if (p[j]=='$')
                {
                    dp[i][j] = (dp[i][j-1] && i==M);    // $要求p[1:j-1]必须完整匹配s串，否则失败
                }
                
                if (j==N && dp[i][j]==true) return true;
            }
        return false;
    }
```

Step 5. 本题中，先不考虑'^'的情况下，我们要判断p能否匹配queryString的某个子串，可以遍历这个子串的起始点start。于是问题转化为，判断p能否匹配queryString.substr(start)或它的前缀。
```cpp
int flag = 0;
for (int start = 0; start < queryString.size(); start++)
{
    if (canSearch(formatString, queryString.substr(start)))
    {
        flag = 1;
        ans.push_back(true);
        break;
    }                    
}
if (flag==0) {
    ans.push_back(false);
```                

Step 6. 本题中的'^'比较特殊。如果p存在这个符号，那么直接要求p能匹配queryString或它的前缀子串，而不能是任意中间开始的某个子串。于是
```cpp
if (formatString[0]=='^')
{
    formatString = formatString.substr(1);
    ans.push_back(canSearch(formatString, queryString));         
}
```

将以上六步结合起来，就实现了完整的regex_search的功能。
