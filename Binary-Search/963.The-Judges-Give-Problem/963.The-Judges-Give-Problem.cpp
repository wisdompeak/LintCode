class Solution {
public:
    /**
     * @param E: the number of easy problems
     * @param EM: the number of "easy and medium" problems
     * @param M: the number of medium problems
     * @param MH: the number of "medium and hard" problems
     * @param H: the number of hard problems
     * @return: nothing
     */
    long long theNumberOfContests(long long E, long long EM, long long M, long long MH, long long H) 
    {
        long long left = 0;
        long long right = LLONG_MAX;
        while (left < right)
        {
            long long mid = right-(right-left)/2;
            
            if (isOK(mid, E, EM, M, MH, H))
                left = mid;
            else
                right = mid - 1;
        }
        
        return left;
    }
    
    bool isOK(long long x, long long E, long long EM, long long M, long long MH, long long H)
    {
        if (x > E+EM) return false;        
        if (E < x) EM -= (x-E);
        
        if (x > MH+H) return false;
        if (H < x)MH -= (x-H);
        
        if (x > EM+M+MH) return false;
        
        return true;
    }
};
​​
