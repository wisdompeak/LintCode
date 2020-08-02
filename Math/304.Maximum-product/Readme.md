同 LeetCode 628. Maximum Product of Three Numbers

#### 思路1：

考虑这三个数的正负号：
pos(m), neg(n)
3+ => pos[m-3]*pos[m-2]*pos[m-1]
2+1- => pos[0]*pos[1]*neg[n-1]
1+2- => pos[m-1]*neg[0]*neg[1]
3- => neg[n-3]*neg[n-2]*neg[n-1]
0 => 0


#### 思路2：

1. 所有元素大于0：	| X... X X X  	
   	肯定取最大的三个正数。即 nums[N-3]*nums[N-2]*nums[N-1]

2. 仅有一个元素小于0：	X | X... X X X  	
	单个负数无法使用，依然只能取最大的三个正数。即 nums[N-3]*nums[N-2]*nums[N-1]

3. 至少两个元素小于0：	X X | ... X X X  
	尝试取绝对值最大的两个负数组合成一个较大的正数？（不可能取更多或者其他的负数）
	max { nums[N-3]*nums[N-2]*nums[N-1], nums[0]*nums[1]*nums[N-1]}

4. 	仅有一个元素大于0：	X X ... X X | X  	
 	仅能取最小的两个负数和一个正数。即 nums[0]*nums[1]*nums[N-1]

5. 	所有元素小于0：	X X ... X X |
	仅能取最小的两个负数和最大的一个负数。即 nums[0]*nums[1]*nums[N-1]
