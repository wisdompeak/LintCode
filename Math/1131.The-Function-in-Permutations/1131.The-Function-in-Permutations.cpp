class Solution {
public:
    /**
     * Return [minF(n), maxF(n)].
     * @param n int整型 An integer.
     * @return int整型vector
     */
    int findMin(int n)
    {
        if (n%4==1|| n%4==2) return 1;
        else return 0;
    }
    vector<int> minMax(int n) 
    {
        int mn = findMin(n);
        int mx = n - findMin(n-1);
        return {mn,mx};
    }
};
