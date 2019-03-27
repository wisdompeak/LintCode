class Solution {
public:
    /**
     * @param A: 
     * @return: nothing
     */
    long long playGames(vector<int> &A) 
    {
        long long left = 0;
        long long right = 0;
        for (auto x:A) right+=x;
        
        while (left<right)
        {
            long long mid = (right-left)/2+left;
            if (isOK(A,mid))
                right = mid;
            else
                left = mid+1;
        }
        return left;
        
    }
    
    bool isOK(vector<int>&A, long long N)
    {
        long long count = 0;
        for (int i=0; i<A.size(); i++)
        {
            if (A[i]>N) return false;
            count+=N-A[i];
        }
        return count>=N;
    }
    
};
