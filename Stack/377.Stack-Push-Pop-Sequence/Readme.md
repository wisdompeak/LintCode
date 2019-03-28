377. Stack Push-Pop Sequence

Given a push sequence and pop sequence of a stack. Decide whether there are legal sequences.

Example 1:

Input: push = [1, 2, 3], pop = [3, 2, 1]

Output: True

Explanation: Push 1, 2, 3 and pop 3, 2, 1.

Example 2:

Input: push = [1, 2, 3], pop = [3, 1, 2]

Output: False

Explanation:
If we want to first pop 3, the 1 and 2 must already in the stack, and 2 is on the top of 1, in this situation, 1 can not be popped before 2.

Notice

The number of elements does not exceed 1000

本题的思路还是比较巧妙的．我们可以这么考虑：
```
＿＿A'＿＿A＿
       ＿B＿｜
       ｜＿＿＿C＿＿＿
 ＿＿＿＿＿＿＿＿＿＿＿｜
             D 
 ```
 A和Ｂ是镜像对称的，Ｃ和Ｄ是镜像对称的． 
