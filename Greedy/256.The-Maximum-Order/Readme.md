人话翻译：

每天固定最多消耗demand个物品。
已经有一批物品onHand，onHand[i]表示了每件物品的保质期
还有一批物品supplier可供采购，supplier[i]表示了每件物品的保质期。

问onHand的物品能否都在保质期前消耗完？不能的话返回-1.
如果onHand都消耗完了，你最多还能消耗多少supplier可以提供的物品？（也必须在保质期前消耗）

1 <= m,n <= 10^5
1 <= demand <= m+n
0 <= onHand[i],supplier[j] <= 10^5
​​
=====================

直观的模拟：

假设每天固定计划消耗demand个物品。
need: {0, demand}, {1, demand}, {2, demand}, {3, demand}, {4, demand}, ...

如果今天有到期的onHand，就今天消耗它；如果依然有剩今天到期的onHand，就在昨天消耗它；还有？就在前天消耗它...
need: {0, demand}, {1, demand}, {2, demand-2}, {3, 0}, {4, 0}, ...
如果历史上所有天的总消耗额度都不够，那么必然有浪费onHand。

然后查看supplier能提供多少剩余的需求。
对于第i天的剩余需求need，查看supplier有多少保质期在i天前的物品。两个指针分别在need和supplier走一遍即可。

PS：对于onHand，我们为什么优先考虑使用时间上较晚的额度去消耗？
这是因为supplier可能会比较早过期。我们留下更多的较早时间的额度，可以更多地去消耗supplier.
