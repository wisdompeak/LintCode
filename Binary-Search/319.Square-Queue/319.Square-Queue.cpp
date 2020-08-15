class Solution {
public:
    /**
     * @param height: n people's height
     * @return: return the maxium number of people in square matrix
     */
    int MaxPeopleNumber(vector<int> &height) 
    {
        int left = 1, right = sqrt(height.size());
        
        sort(height.begin(), height.end());
        
        while (left<right)
        {
            int mid = right-(right-left)/2;
            if (isOK(mid, height))
                left = mid;
            else
                right = mid-1;
        }
        
        return left*left;
        
    }
    
    bool isOK(int k, vector<int>&height)
    {
        int j = 0;
        int count = 0;
        // cout<<k<<endl;
        for (int i=0; i<height.size(); )
        {
            while (j<height.size() && j-i<k && height[j]-height[i]<=2)
                j++;
                            
            if (j-i==k)
            {
                count++;
                i = j;
            }
            else
            {
                i++;
            }
            
        }
        return count>=k;
    }
};
