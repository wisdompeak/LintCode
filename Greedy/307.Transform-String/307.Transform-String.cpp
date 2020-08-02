class Solution {
public:
    /**
     * @param A: a string A
     * @param B: a string B
     * @return: return the minimum number of operations to transform
     */
    int transform(string &A, string &B) {
        int m = A.size(), n = B.size(); 
        if (n != m) 
            return -1; 
        int count[256]; 
        memset(count, 0, sizeof(count)); 
        for (int i=0; i<n; i++)   
            count[B[i]]++; 
        for (int i=0; i<n; i++)  
            count[A[i]]--;       
        for (int i=0; i<256; i++)
        if (count[i] > 0) 
            return -1; 
  
        int ret = 0; 
        for (int i=n-1, j=n-1; i>=0; ) 
        { 
            while (i>=0 && A[i] != B[j]) 
            { 
                i--; 
                ret++; 
            }
  
            if (i >= 0) 
            { 
                i--; 
                j--; 
            } 
        } 
        return ret; 
    }
};
