### 1475.Minimum-Legal-Bracket-Sequence

#### Description
Give a non-empty even-length string s containing "(", ")" and "?". For each "?", we can use "(" or ")" instead, but each replacement will pay a price. Replaced with "(" the cost of the array is a, which means that the cost of replacing the first i "?" with "(" is a[i]. Similarly, the cost array replacing with ")" is b, which means that the cost of replacing the first i "?" with ")" is b[i]. Now it is required to replace all "?" so that the sequence of parentheses after replacement is legal.what is the minimum cost of the output? If a legal bracket sequence is not available, -1 is output. A legal bracket sequence requires that each "(", on the right side of it") can match.

#### Analysis
此题类似与 LeetCode 678. Valid Parenthesis String. 同样设置Lower,Upper,分别表示未匹配的左括号的最小值和最大值.

当s[i]=='(',两者都加一. 当s[i]==')',两者都减一. 当s[i]=='?',注意问号能代表左括号,也可以代表右括号,所以分别对应的是upper++和lower--.

在遍历的过程中,如果发现lower<0,说明右括号(包括问号所代表的右括号)太多了,我们得拿出一个问号,杜绝它作为右括号的可能,确定它只能当做左括号,所以Lower重置为1.注意,因为本题中的问号不能当做空号使用,所以重置为1而不是0.此时,我们就可以在当前选项当中,选出一个性价比最高的问号,确定它是左括号.什么叫当前的选项?就是当前我们扫过k个问号的话,我们就在a,b的前k个元素中找a-b最小的那个.

另外,在遍历的过程中,如果发现upper<0,说明即使把所有的问号当做左括号来用,都无法抵消题目中已经给出的右括号,此时就提前判断false并退出.

需要注意的是,全部字符串扫完之后,那些"确定必须为左括号的问号"数目,恰好就是最终"应该为左括号的问号"的数目.这是因为扫描字符串后,我们必须保证左右括号已经恰好匹配.所以我们不需要再做其他的操作了.
