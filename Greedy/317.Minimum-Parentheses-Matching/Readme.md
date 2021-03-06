#### 题意

给一个含有'('，')'，'*'的字符串，允许把'*'变为'('或')'或''，求最短的括号匹配合法序列，
若有多个答案，返回字典序最小的那个。若不存在解则返回“No solution!”。

#### 思想：贪心法 two pass

观察 ：
```
**((***)) ...
```
因为我们希望尽量地少用星号，所以暂时尽量忽略星号。
我们一路追踪左右括号的个数left和right，此时此刻，我们发现left==right。也就是说，所有的星号我们都可以不做修改也能使式子合法。

```
**((***))) ... 
```
此时发现left<right，如果不启用任何星号的话，这个式子注定非法。
既然必须将一个星号转为左括号，那么改哪个星号呢？为了使字典序最小，选最左边的（将左括号尽可能地放在最前面）！
（想想一下我们尽量在一个整数前堆0必然能得到最小的数）
当然， 如果此时手头没有星号，那么就无解。

```
(*((***))) ... 
```
如上，修改之后，再次实现了left>=right，避免了“突然死亡”。

```
(*((***)))((** 
```
如上，依次操作，直到遍历完之后，可以保证这个过程中永远left>=right（即每一个右括号都一定有匹配的左括号）
注意，此时我们要明确一个结论：至此所有的修改都是“必要操作”（非改不可，而且是最优策略）。

OK，one pass结束之后，如果现在的情况是left>right，依然不合法。怎么办呢？

反过来再做一遍类似的操作：

从右往左的遍历过程中，要保证永远left<=right。（即每一个左括号都一定有匹配的右括号）
```
... (()** 
```
此时发现left>right，必须修改一个之前遇到的星号变成右括号。选哪个星号最好呢？同理，选最右边的！
当然， 如果此时手头没有星号，那么就无解。

同理，我们可以分析出，这次的one pass也是“必要操作”。

两次“必要操作”之后，我们发现此时必然满足left==right，所以这个结果也是“充分的”。
于是没有必要再做多余的操作了，输出此时的字符串就是答案。

Similar problem: LeetCode 1249. Minimum Remove to Make Valid Parentheses
