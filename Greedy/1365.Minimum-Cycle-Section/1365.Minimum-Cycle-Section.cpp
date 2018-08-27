class Solution {
public:
    /**
     * @param array: an integer array
     * @return: the length of the minimum cycle section
     */
    int minimumCycleSection(vector<int> &array) 
    {
        int N = array.size();
        vector<int>prev(N,-1);
        int i = 1;
        int j = 0;
        
        while (i<N)
        {
            if (j==0 && array[i]!=array[j])
            {
                prev[i] = -1;
                i++;
            }
            else if (array[i]==array[j])
            {
                prev[i]=j;
                i++;
                j++;
            }
            else
            {
                j--;
                j = prev[j];
                j++;
            }
        }
        return (N-1)-prev[N-1];
        
    }
};
