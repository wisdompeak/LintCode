给出一系列单词 words，以及两个不同的单词 wordA 和 wordB，请找出最近的两个 wordA 和 wordB 的间距。

如果 words 中不存在 wordA 或 wordB，那么返回 -1。

算法：
将wordA和wordB在words中的所有位置（index）存放在两个数组里。
```
A: [1, 3, 7, 12]
B: [2, 5]
```
对于B的每一个元素b，用二分法在A中寻找最近的元素。

具体地，可以找写出用二分法在A中寻找第一个大于等于b的元素的位置pos，然后比较A[pos]和A[pos-1]哪个更接近b。


优化：

当wordB的occurance比wordA更多时，先调转两个单词的顺序再做。
