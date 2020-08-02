#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;   
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

class Solution {
public:
    long long sortedArrangement(vector<int>& nums) 
    {
        ordered_set o_set; 
        long long ret = 0;        
        for (auto x:nums)
        {
            long long k = o_set.order_of_key(x);
            long long t = min(k, o_set.size() - k);
            ret += t*2+1;
            o_set.insert(x);            
        }
        return ret;
    }
};
