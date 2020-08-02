class Solution {
public:
    /**
     * @param A: an array of integers
     * @param B: an array of integers
     * @return: return a integer indicating the number of fair indexes.
     */
    int CountIndexes(vector<int> &A, vector<int> &B) 
    {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int N = A.size();
        int preA = 0, preB = 0;
        int count = 0;
        for (int i=0; i<N-1; i++)
        {
            preA+=A[i];
            preB+=B[i];
            if (preA==sumA-preA && preA==preB && preB==sumB-preB)
                count++;
        }
        return count;
        
    }
};
