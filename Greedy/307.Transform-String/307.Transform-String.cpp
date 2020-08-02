class Solution {
public:
    /**
     * @param A: a string A
     * @param B: a string B
     * @return: return the minimum number of operations to transform
     */
    int transform(string &A, string &B) {
        vector<int>count1(256,0);
        vector<int>count2(256,0);
        for (int i=0; i<A.size(); i++)   
            count1[A[i]-'A']++; 
        for (int i=0; i<B.size(); i++)   
            count2[B[i]-'A']++;  
        if (count1!=count2)
            return -1; 
  
        int ret = 0; 
        int i = A.size()-1, j = A.size()-1;
        while (i>=0) 
        { 
            while (i >= 0 && A[i] == B[j]) 
            { 
                i--; 
                j--; 
            }
            
            while (i>=0 && A[i] != B[j]) 
            { 
                i--; 
                ret++; 
            }
        } 
        return ret; 
    }
};
