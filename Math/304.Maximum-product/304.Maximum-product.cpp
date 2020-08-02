class Solution {
public:
    /**
     * @param nums: Unordered array
     * @return: return the largest product
     */
    long long MaximumProduct(vector<int> &nums) {
        sort(nums.begin(),nums.end());
        int N=nums.size();
        return max(1ll*nums[0]*nums[1]*nums[N-1], 1ll*nums[N-3]*nums[N-2]*nums[N-1]);
    }
};
