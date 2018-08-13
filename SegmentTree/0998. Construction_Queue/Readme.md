### 0998. Construction_Queue

此题的一般解法是：设置一个result数组，并且元素都为零。我们将题目给的数组从小到大排序，从最大的数开始处理。如果这个最大数在数组中有k个比它小的数，那么在result数组里第k+1个零即为这个数的位置，并且将result对应的位置安置为这个数。然后同理，依次处理倒数第二大的数，第三大的数...

大致的代码如下：
```cpp
        vector<pair<int,int>>q;
        for (int i=0; i<arr1.size(); i++)
            q.push_back({arr1[i],i});
        sort(q.begin(),q.end());
        
        int N = arr1.size();
        vector<int>results(N,0);
        for (int i=N-1; i>=0; i--)
        {
            int count = 0;
            int id = q[i].second;
            for (int j=0; j<N; j++)
            {
                if (results[j]==0) count++;
                if (count == arr2[id]+1)
                {
                    results[j] = arr1[id];
                    break;
                }
            }
        }
        
        return results;
```
这种算法的时间复杂度是o(N^2)。遇到大case会超时。问题在于每次循环都要在result里从头开始寻找第K+1个零的位置，显得累赘和重复。一个比较好的方法是利用线段树。

这里的线段树的构造比较简单，对于0~N个数，我们在初始化时直接把这棵树细化到完全满二叉树，即底层的每个节点代表的就是[a,a+1)，不需要在后续的过程中再细化。对于一个节点代表的[a,b)区间，其status表示的是这个区间内含有零的个数。于是我们要找第K个零的位置，只要看node->left->status是否大于等于K：如果是的话就在左子树里找，否则就在右子树里找。知道搜索到最底层的节点，其区间[a,a+1)就代表a就是我们需要在result里赋值的位置。
```cpp
    int FindKthZero(SegNode* node, int K)
    {
        node->status = node->status-1;
        if (node->a+1 == node->b)
            return node->a;
        int mid = (node->b-node->a)/2+node->a;
        if (node->left->status>=K)
            return FindKthZero(node->left,K);
        else
            return FindKthZero(node->right,K-node->left->status);
    }
```    
