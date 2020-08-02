给定一系列会议的开始时间、结束时间[[s1,e1]，[s2,e2]，…(si < ei)及他们的价值。
你在同一时刻只能参加一个会议，请问你可以获得的最大价值是多少？

0≤len(meeting)=len(value)≤10000
1 ≤ meeting[i][0] < meeting[i][1] ≤ 50000

LeetCode 1235. Maximum Profit in Job Scheduling

maximum number of non-overlap intervals


解法1：O(time)

定义截止i时刻能收获的最大价值为dp[i]。
对于任何一个时刻点i，它的最大价值一定是在恰好开完一场会之后获得的。
Why? 如果时刻点i不是一场会议的结束点的话，那么说明它之前要么没有会，要么被一场正在进行中的会占据了（却没有收获），都不是最优的安排。
于是我们就遍历在时刻i恰好结束的会议k，显然，i时刻的价值，等于会议k开始时刻的价值，加上会议k本身的价值。
```
dp[i] = dp[i-1]
for (k: all available meetings that end at time i)
	dp[i] = max(dp[i], dp[meeting[k][0]] + value[k])
```    
此外还要注意，dp[i]初始默认值不是0，而是dp[i-1]（也就是前一分钟时刻已经得到的价值），因为已经获得的价值不会消失。

解法2：O(NlogN)

在评估价值的时候，我们只需要关心每个会议结束的时刻。因为任何会议进行中、或者没有会议正在进行的时刻点，都不会是有价值增量的时刻。
所以当time的范围很大的时候，解法1的效率很低。事实上，我们只要考虑所有的会议结束时刻，需要记录的数据大大减少。

同理定义dp[i]是时刻i的最大收益。假设时刻i是会议k的结束时刻，显然依照之前的分析，有更新dp[i]的机制：
dp[i] = dp[meeting[k][0]] + val[k]。

但是会议k的开始时刻，我们之前并不会保证会有dp的记录（因为meeting[k][0]并不一定是某个其他会议的结束时刻）。
那么dp[meeting[k][0]]怎么求呢？其实dp[meeting[k][0]]，就等于会议k之前的一场会议的结束时刻的价值。
只要我们将所有的会议按照结束时刻排序，对于任何时刻t，我们都可以轻松用二分法定位到它之前的一场会议是哪个。
```cpp
	int curVal = 0;
	for (int k : all meetings sorted by end time)
        {            
            int end = meeting[k][1];
            int start = meeting[k][0];
            int val = val[k];

            int lastEnd = findLastMeetingEndTime(start);
            dp[end] = max(curVal, dp[lastEnd] + val); // 如果这个会议价值很低，索性不开。
            curVal = dp[end];
        }
    return curVal;
```
特别注意，我们用了一个curVal来保证装入dp的数值一定是递增的。因为dp所装的都是递增时刻的最大价值，而最大价值是不可能因为时间的增加而减少的。

具体的代码实现，C++可以利用有序set装下所有的endTimes，对给定的时刻，实现快速查找上一个会议的结束时刻。
