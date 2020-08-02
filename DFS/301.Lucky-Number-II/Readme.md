由一个k位数的幸运数，可以确定地生成若干个k+1位的幸运数。（大概有2^k个，但实际远比这个数字少）
abc => 1, 1+a , 1+a+b, 1+a+b+c
                       1+a+b-c
                1+a-b, 1+a-b+c
                       1+a-b-c
          1-a,  1-a+b, 1-a+b+c
                       1-a+b-c
                1-a-b, 1-a-b+c
                       1-a-b-c

       2, ......
       3, ......
       。
       9, ......
       aabc  // one sepcial case: repeat the first digit at the head, except for the single "7"

每一位digit要求满足 0<=digit<=9

一个8位的luck number 最多生成256个9位的luck number.感觉不是很大。
可以尝试将所有小于1e9的幸运数都生成，排序。然后利用二分搜索找到[l,r]的位置，计算索引的差值。

