#### 题意
对于有一个排好序的数组，它的元素可以从队首或者队尾加入或弹出，即双端队列。
现在给你一个待插入元素的数组，请按顺序插入到一个空数组中，并计算出最少操作次数。
一次操作指的是从队列里弹出一个数（首或者尾）或加入一个数。

待插入的数组 nums 的长度为 n，1 <= n <= 1e5

数组中的每个数字各不相同，1 <= num <= 1e5

#### 题解
突破口：为什么会给这个限制条件： “数组中的每个数字各不相同，1 <= num <= 1e5” 有什么意义？会影响时间复杂度吗？
理论上并不会，但提示我们从数值的范围入手（类似于桶排序、二分搜值的思维切入方式），是否有可能带来某个维度上的简便？

我们设计vector<bool>val(1e5+1), 令val[i]的true/false表示数组i是否已经在队列中。

那么对于任何新加入的数字i，我们选择从队首插入还是队尾插入的依据，就是看i之前有多少个元素在队列中 vs i之后有多少个元素在队列中。
很朴素的贪心思想：队列哪一端的元素数目少，那么弹出+加入+回填的代价就少。

e.g. 1 0 1  X   1 0 0 0 0 0 1 1 0 0 1 0 1 
            ^
我们想在队列中插入第八个数，大小是4。我们就看val数组中idx=4之前有多少个1，假设是k1; 相应idx=4之后的1的个数就是 k2 = 7 - k1;

因此本题归结为：如何设计高效的数据结构和算法，快速计算val数组中某个区间的1的个数（即某个区间的元素和）

候选方案：树状数组(binary index tree) 或者 线段树(segment tree)

无论哪一种方案，需要支持这么几个操作：
1. update(i, 1) ：将val数组的第i个元素置为1
2. querySum(a, b)：计算val数组的区间[a,b]的元素和。
这两个操作都是O(logN)的时间复杂度。


那么本题的核心伪代码大致是：

```cpp
        long long result = 0;
        
        for (int i = 0; i < n; i++) {
            int k1 = querySum(1, nums[i] - 1);
            int k2 = i - k1;
            result += 2 * min(k1, k2) + 1;
            update(nums[i], 1);
        }
        
        return result;
```
因此本题的总时间复杂度是O(NlogN)

关于树状数组和线段树的具体代码，大家可以在网上搜各种模板。这里给一个BIT的模板。
BIT的思想是，将val数组映射成一个bit数组。对val的任何操作，都可以转换成在bit数组上进行。而bit的index包含了二分的思想。
举个（不精确的）例子，假设bit[n/2]代表的是 sum(val[1]+...+val[n/2])，那么 querySum(1,n/2+1)就等于bit[n/2]+val[n/2+1]，而不需要累加所有val的元素。
至于这个映射过程，虽然代码很精妙，理解起来并不容易，把模板抄下来就可以了。
（特别注意，bit数组是1-index）


=============================

顺便说一下，如果除去 “数组中的每个数字各不相同，1 <= num <= 1e5” 这个条件限制，本题还是可以用O(NlogN)实现。

上面的解法中，因为val的大小是固定的（因为num的数值大小有上限），所以真正将一个新数“插入”队列的操作其实是 o(1). 
如果val的大小无法提前预知，那么每次插入的时候val的大小动态变化，对应的bit就无法正常工作。

解决方法是利用红黑树，以o(logN)的时间实现插入。
而在计算k1的时候，也就是 querySum(1, nums[i] - 1)时，有一种高端红黑树的数据结构依然能以 o(logN)的时间计算出来（有点类似bit的原理）。
这种bit+红黑树的数据结构在 GNU C++ 有支持。代码如下：
```cpp
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
```
参考文献：https://codeforces.com/blog/entry/11080

注意，lintcode的编译环境不支持上面的代码。
