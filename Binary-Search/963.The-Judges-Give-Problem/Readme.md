### 963. The Judges Give Problem

#### Description
```
题目难度分为“简单题”、“中等题”、“难题”三个等级。
评委们已经出好了E 道简单题， M 道中等题， H 道难题。
然后评委们又出了 EM道“简中”题和 MH 道“中难”题。
所谓的“简中题”是指该类型的题既可以归类为“简单题”也可以归类为“中等题”。
所谓的“中难题”是指该类型的题既可以归类为“中等题”也可以归类为“难题”。
评委们规定：一场比赛必须包含 3 道题，其中 1 题是“简单题”， 1 题是“中等题”， 1 题是“难题”。
每道题目至多只能出现在一场比赛中。现在，评委们最多可以组织多少场比赛？

0≤E,EM,M,MH,H≤10^​18
```

### 思路：
```
本题的数学思维是：考虑如何最优地将EM拆分为EM = E1+M1, 将MH拆分为 MH = M2+H2，使得
最大化： min{E + E1, M + M1 + M2, H + H2}
这个角度切入的话不是很容易。

更容易的解决方法就是二分搜值。猜测答案是x，然后判定能否实现。能实现的话就猜测更大的x，否则就猜测更小的x。

如何判定能否构成x套题呢？很简单，根据已有的条件，逐个查看能否凑成x道Easy, Medium和Hard
```
```cpp
    bool isOK(long long x, long long E, long long EM, long long M, long long MH, long long H)
    {
        if (x > E+EM) return false;    // E+EM 都凑不够x道Esay，直接判负
        if (E < x) EM -= (x-E);		   // 如果E太少，那么EM里就只有 EM-(x-E) 道能作为medium
        
        if (x > MH+H) return false;		// H+MH 都凑不够x道Hard，直接判负
        if (H < x)MH -= (x-H);			// 如果H太少，那么MH里就只有 MH-(x-H) 道能作为medium
        
        if (x > EM+M+MH) return false;	// 查看剩下的 M+EM+MH 是否够 x道 medium
        
        return true;
    }
```cpp
