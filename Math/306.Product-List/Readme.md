
```
	offset     offset+n
	  |____________|

 |_________|___________|    
 0       len1        len1+len2

      |<-->|<----->|   
```

range1: 
s1 = min(offset, len1);
e1 = min(offset+n, len1);

range2: 
s2 = max(offset, len1);
e2 = min(offset+n, len1+len2);

以上的起止点关系一定满足 s1<=e1, s2<=e2;

此外需要特别处理当 s1==e1 和 s2==e2 的特例（表示对应的list并没有物品被覆盖）。
根据题意，“列表区间为空”（没有遇到）和“列表被跳过”需要有不同的输出。

对于list1，s1==e1只可能意味着被跳过，需要输出{0,0}
对于list2，s2==e2可能意味着尚未覆盖或者已被跳过，取决于offset+n和len1的位置关系，分别需要输出{0,0}或{len2,len2}
