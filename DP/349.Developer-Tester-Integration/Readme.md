### 349. Developer-Tester Integration

#### description
```
一家软件公司正在组建由特定数量的员工组成的团队。有两种类型的员工：开发人员和测试人员。
他们希望确保开发人员和测试人员很好地集成在一起，因此他们决定限制测试人员和开发人员可以与相同类型的员工连续就座的数量。
给定所需的团队规模和这些限制，公司可以采用多少种不同的方式组建团队？

注意：由于答案的数量可能会很大，请返回其模10^9+7的结果。
2≤n≤10^5
2≤d,t≤10^5
1≤len(queries)≤10^5

翻译：
给出数字n，问有多少种长度为n的01序列，使得任何连续的0不超过d，任何连续的1不超过t。
```
#### 分析：
```
令dp0[i]表示只考虑前i个元素、且第i位我们放置0的话，总共有多少种方法。
            X X X X X X 0

我们考虑第i-1位可以放什么？可以放1是没问题的。可以放0吗？只要截止i位置不超过d个0，也是可以的。
这就提醒我们我们考虑d种情况：即i之前连续的0有多少个。假设 d = 3，那么A[i]可以置0的前提只有这么几种情况
            X X X X X 1 0
            X X X X 1 0 0
            X X X 1 0 0 0
这三种情况就对应着：第i-1位放置1的方案数，第i-2位放置1的方案数，第i-3位放置1的方案数。
显然， 我们同理定义dp1[i]表示只考虑前i个元素、且第i位我们放置1的话，总共有多少种方法。
于是就有 dp0[i] = sum{dp1[k]}, k=i-1,i-2,...,i-d

类似的，我们可以写出 dp1[i] = sum{dp0[k]}, k=i-1,i-2,...,i-t

这是一个你中有我我中有你的转移方程。
for (int i=0; i<n; i++)
{
    for (int k=i-1; k<=i-d; k++)
        dp0[i] += dp1[k];
    for (int k=i-1; k<=i-t; k++)
        dp1[i] += dp0[k];

}
由此我们可以看到，时间复杂度是o(n*d)或者o(n*t). 但是根据本题的数据范围，这个时间复杂度是超时了。

怎么办呢？关键是我们看到，这个sum累加的是一段固定长度的dp滑窗。
我们每计算一个新的dp0[i]，所需要的滑窗相比于计算dp0[i-1]所用的滑窗，只不过更换了首尾两个元素而已。
不需要重新遍历滑窗内所有的元素再计算他们的和。
for (int i=0; i<n; i++)
{
    dp0[i] = windowSum_dp1; // i之前的、d个dp1的元素的滑窗
    dp1[i] = windowSum_dp0; // i之前的、t个dp0的元素的滑窗
    
    update windowSum_dp1 by adding dp1[i], dropping dp1[i-d]
    update windowSum_dp0 by adding dp0[i], dropping dp0[i-t]

}

另外，windowSum也可以用前缀和之差来替代：preSum[i]-presum[i-d-1] = windowSum[i-d:i]

类似题： LeetCode 1621    Number of Sets of K Non-Overlapping Line Segments
```
