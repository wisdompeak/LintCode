分析：类似于背包问题。有120分钟的容量，有一些物品的价值和代价，求最大总价值。

基本模板

for (int i: 遍历物品)
{
    dp_temp = dp;
    for (int t: 遍历容量)
        dp[t] <- dp_temp[t-cost[i]] + val[i];
}

ans = max(dp[t])  over all t
