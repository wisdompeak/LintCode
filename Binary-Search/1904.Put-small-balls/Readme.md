#### 题意描述
n个桶中小球的个数已知,可以操作k次(每次从桶中取出一个球,或者添加一个球),每个桶有规定的最大容量W[i]。求操作后{两相邻桶之间的最大差值}的平方的最小值。
```
k = 6
A = [1,2,3,4,5]
W = [15,15,15,15,15]

n≤100
W[i]≤100
```

#### 题解
贪心的思想？尝试优先处理差值最大的一对桶？优先处理最多的桶？优先处理最少的桶？No

high-level思想：二分搜值，猜测一个m，查看是否能够用不多于k次的操作，使得相邻两桶的绝对差值最大不超过m。显然 0 <= m <= 100.
如果成功，可以尝试更小的m（让各个桶的球数更接近）；如果不成功，说明这个目标太激进，只能尝试更大的m。

子问题：给定m和k，查看是否能够用不多于k次的操作，使得相邻两桶的绝对差值最大不超过m。

考虑第i个桶（经过操作后）的数量只受第i-1个桶的数量的制约，与第i-2个桶无关。典型的“无后效性”，适合DP。

考虑到每个桶的数量最多只有100个，可以枚举第i个桶的所有数量作为状态。
定义dp[i][a]表示第i个桶（经过操作后）放a个球的话，需要至少多少操作数才能满足条件（i.e. 相邻两桶的绝对差值最大不超过m）
```
dp[i][a] = max {dp[i-1][b] + abs(a - A[i]) } for b = 0,1,...,W[i-1]
```
其中还要求b和a之间的绝对值之差不超过k。

答案：如果有任何一个a使得 dp[n-1][a] <=k，说明操作成功。

