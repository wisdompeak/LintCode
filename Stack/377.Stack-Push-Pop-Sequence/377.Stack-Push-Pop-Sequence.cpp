class Solution {
public:
    /**
     * @param push: the array push
     * @param pop: the array pop
     * @return: return whether there are legal sequences
     */
    bool isLegalSeq(vector<int> &push, vector<int> &pop) 
    {
        int j = 0; 
        int len = push.size();
        
        stack <int> st; 
        for(int i = 0; i < len; i++)
        { 
            st.push(push[i]); 
          
            while (!st.empty() && j < len && st.top() == pop[j])
            { 
                st.pop(); 
                j++; 
            } 
        } 
      
        return j == len; 
    }
};
