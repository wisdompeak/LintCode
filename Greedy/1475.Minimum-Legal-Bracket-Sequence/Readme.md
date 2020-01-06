### 1475.Minimum-Legal-Bracket-Sequence

#### Description
Give a non-empty even-length string s containing "(", ")" and "?". For each "?", we can use "(" or ")" instead, but each replacement will pay a price. Replaced with "(" the cost of the array is a, which means that the cost of replacing the first i "?" with "(" is a[i]. Similarly, the cost array replacing with ")" is b, which means that the cost of replacing the first i "?" with ")" is b[i]. Now it is required to replace all "?" so that the sequence of parentheses after replacement is legal.what is the minimum cost of the output? If a legal bracket sequence is not available, -1 is output. A legal bracket sequence requires that each "(", on the right side of it") can match.

#### Analysis
此题看上去类似于 LeetCode 678. Valid Parenthesis String. 但还是有不同之处。

我们来回顾一下那一题：通配符可以表示为空字符，所以待填充的左括号和右括号的数目不确定。因此那题的解法中需要设置Lower,Upper两个变量,分别表示未匹配的左括号的可能最小值和可能最大值：当s[i]=='(',两者都加一. 当s[i]==')',两者都减一. 当s[i]=='?',注意问号能代表左括号,也可以代表右括号,也可以代表空，所以分别对应的是upper++和lower--.在遍历的过程中,如果发现lower<0,说明右括号太多了,我们得拿出一个问号,杜绝它作为右括号的可能,所以Lower重置为0.如果发现Upper<0，说明截至当前位置时右括号注定多于左括号，返回无解。全部遍历完之后，要求Lower必须是零，否则表示左括号注定多余右括号。

再来看本题，最大的区别在于通配符只能表示括号，所以本质上待填充的左括号和右括号的数目都是确定的。本题中只需要一个变量count，来表示未匹配的左括号的可能最小值。在这样的定义下，我们需要做的是尽量对通配符填充为右括号，也就是说：
```
if (s[i]=='(')
  count++;
else if (s[i]==')')
  count--;  
else
  count--;      
```
而当count变为-1时，说明右括号太多了，我们必须将之前的某个被用作右括号的通配符改为左括号。这样count重置为1，注意不是重置为0.此时,我们可以在已经处理过的所有通配符中,选出一个性价比最高的问号,来重置它为左括号（之前默认处理为右括号）。什么叫“性价比”最高？就是对应a-b最小的那个问号。我们可以提前处理将每个问好所对应的a-b放入一个优先队列中（小的排在前面）。注意，一旦我们选中了这个问号确定为左括号，就需要将其从这个pq中弹出，以后不能再用它了。

因此，在遍历的过程中,如果发现count<0需要重置一个问号为右括号，但是pq的队列已经是空了，说明即使把所有已经处理过问号都当做左括号来用，也无法抵消题目中已经给出的右括号，此时就提前判断false并退出。

需要注意的是，全部字符串扫完之后，我们需要满足```count==0```，否则便认为无法配对。这与LC678中lower的要求是一致的。
