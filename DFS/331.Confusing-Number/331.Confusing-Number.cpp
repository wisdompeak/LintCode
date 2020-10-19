#include "bits/stdc++.h"
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * the number of confusing numbers
     * @param k int整型 the number of auction participants2
     * @return int整型
     */
    unordered_map<char,char>Map={{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
    int count = 0;    
    int N;
    string n;
    
    int theConfusingNumbers(int N) {
        this->N = N;
        n = to_string(N);
        
        count = 0;
        for (int l=1; l<n.size(); l++)
        {
            count += perm(l) - symmetric(l);
        }
       
        for (long x: {1,6,8,9})
            dfs(x,1);
        return count;
        // write code here
    }
    
    long perm(int l)
    {
        if (l==1) return 4;
        return 4*4*pow(5,l-2);
    }
    
    long symmetric(int l)
    {
        if (l==1) return 2;
        if (l%2==0)        
            return 4*pow(5,l/2-1);
        else
            return 4*pow(5,l/2-1)*3;
    }
    
    void dfs(long num, int k)
    {
        if (k==n.size())
        {
            if (num>N) return;
            if (isConfusing(num)) 
            {                
                count++;
            }
            return;
        }
            
        for (auto x:{0,1,6,8,9})        
            dfs(num*10+x, k+1);
    }
    
    bool isConfusing(int num)
    {
        string s = to_string(num);
        if (s[0]=='0' || s.back()=='0')
            return false;
        string t = s;
        reverse(t.begin(), t.end());
        for (int i=0; i<t.size(); i++)
            t[i] = Map[t[i]];        
        if (t>n)
            return false;
        
        int i=0;
        int j=s.size()-1;
        while (i<=j)
        {
            if (Map[s[i]]!=s[j])
                return true;
            i++;
            j--;
        }                
        return false;
    }
};
