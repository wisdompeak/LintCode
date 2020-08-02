#### 题意：
给定一个整数数组 A，找到一个具有最大和的连续子数组（子数组最少包含一个元素，并且每个元素都必须是非负整数），返回其最大和。

#### 分析：
LeetCode 53. Maximum Subarray

max-sum subarray: kadane algorithm.

类似dp的思想： dp[i]: 以第i个元素结尾的最大连续子数组（的和）

dp[i]的两种决策：
1. 跟着前面走  				dp[i-1] + nums[i]
2. 自立门户	   				nums[i]
3. 不合法（nums[i]<0）  		0
