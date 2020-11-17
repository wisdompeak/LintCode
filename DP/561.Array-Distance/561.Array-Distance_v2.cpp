class Solution {
public:
    /**
     * @param A: the array A[] in this problem
     * @return: return the minimum distance
     */

    long long arrayDistance(vector<int> &A) 
    {
        priority_queue<int>pq;
        long long ret = 0;
        for (int i=0; i<A.size(); i++)
        {
            if (!pq.empty() && pq.top() > A[i])
            {
                ret += pq.top()-A[i];
                pq.pop();
                pq.push(A[i]);
            }
            pq.push(A[i]);
        }
        
        return ret;
    }
};
