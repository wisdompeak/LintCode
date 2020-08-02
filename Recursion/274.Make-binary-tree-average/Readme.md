#### Description
给定一棵二叉树，返回使其每个节点等于其儿子节点的平均值的最小修改次数。注意：你只能修改树节点的每个值，不能修改树的结构。


#### 分析：

我们试图定义一个递归函数 dfs(node) 来表示对于以node为根的子树，我们的最优解（即是用最少的次数使得所有节点都满足条件）。
我们期望能够得到这样的递归表达式 dfs(node) = something (node, dfs(node->left), dfs(node->right))
首先，这样的something，需要处理node本身节点。node本身无非就是两种选择：改动，不改动。我们分别来看。

1. 当前node要改动
要改动的话，怎么改？改一定是因为要满足 node->val = avg(node->left, node->right). 

所以往下推的关系比较明显：dfs(node) = dfs(node->left) + dfs(node->right) + 1 (这一步是改动node的操作，但是如果恰好有 node->val == avg(node->left->val, node->right->val)这样的特殊情况，这个值可以是 0)   (*)

在这里，我们会注意到一个问题，下一步递归调用 dfs(node->left)的时候，node->left可能也会做类似to change or not to change的决策。如果恰好node->left做出的最优决策是“改动”，那么我们表达式 (*) 就会有问题，也就是node->left->val可能就不是原来的值，而是改动后的值。这就提醒我们dfs的返回值可能需要包含一个“node->val是否已经改变”这样的信息。我们先暂时放下，稍后再提。

2. 当前node不改动

直觉上我们会写出 ```dfs(node) = dfs(node->left) + dfs(node->right) + 0 (因为node不改动)  (**)```

但是```(**)```和```(*)```一比较，我们就会发现dfs的定义出现的问题。在(**)里，如果 dfs(node->left) 和 dfs(node->right) 的最优决策都对应的是“改动”，那么强制node本身不改动是没有道理的。什么时候才会合理呢？比如说，dfs(node->left)的决策是“不改动”，并且 dfs(node->right)的决策是“改动”但改动的值必须是 node->val * 2 - node->left->val，也就是取消了 dfs(node->right)里对node->right->val改动的权利。

所以综上所述，我们会感觉到递归函数 dfs(node)里面需要加上一个参数，就是允许对这个node改动值。有了这个参数，对于上面两类的分析就方便多了。我们再来一次。

1. 当前node要改动，也就是 dfs(node, fixed = 0)
那么有这么几种情况：
```
dfs(node, 0) = dfs(node->left, 0) + dfs(node->right, 0) + 1 其中最后一个1的情境是：dfs(node->left, 0)操作后（可能改动的）node->left，与 dfs(node->right, 0)操作后（可能改动的）node->right，它们的平均值是否与node->val相等。如果不相等，那么node->val就要改动，因此加上这个1.
dfs(node, 0) = dfs(node->left, 1) + dfs(node->right, 0) + 1 其中最后一个1的情境是：（不可能改动的）node->left，与 dfs(node->right, 0)操作后（可能改动的）node->right，它们的平均值是否与node->val相等。如果不相等，那么node->val就要改动，因此加上这个1.
dfs(node, 0) = dfs(node->left, 0) + dfs(node->right, 1) + 1 其中最后一个1的情境是：dfs(node->left, 0)操作后（可能改动的）node->left，与（不可能改动的）node->right，它们的平均值是否与node->val相等。如果不相等，那么node->val就要改动，因此加上这个1.
dfs(node, 0) = dfs(node->left, 1) + dfs(node->right, 1) + 1 注意，这个分支可以省略。因为它不可能是四个分支中的最优解。如果是的话，将这个第四分支和第二分支比较，就会得到 dfs(node->right,1) < dfs(node->right, 0), 这个是不合理的：我们对node->right施加了不能改动的限制，不可能会有单纯的更优的解。
```
此外要注意的是，针对 dfs(node,0)的计算结束之后，我们要永久改变node->val（因为我们允许改变node），或者在向上级传递结果的过程中，报告这个node->val的改变值（这个方案更好）。所以我会将递归函数设计成 {changedNodeValue, minChanges} = dfs(node, fixed)。minChanges表示我们将node这棵子树改造成满足条件的最少操作数（当然根据fixed的设定，觉得node本身是否允许改动）。如果fixed==1，那么chanedNodeValue其实就是原生的node->val; 否则就是改动后的node->val。

2. 当前node不允许改动，也就是 dfs(node, fixed = 1)

首先我们试图写出：
```dfs(node, 1) = dfs(node->left, 0) + dfs(node->right, 0) + 0 （强制是0，因为node不能改动）```。观察一下这个式子，其实是不太可能的。因为你没法保证两个分支：dfs(node->left, 0)和 dfs(node->right, 0)各自得到的最优决策，能够保证两个孩子的平均值就是node->val。
其次我们试图写出：
```dfs(node, 1) = dfs(node->left, 0) + dfs(node->right, 1) + 0 （强制是0，因为node不能改动）```。观察一下这个式子，其实也是不太可能的。因为你没法保证左分支：dfs(node->left, 0)得到的最优决策与右孩子的平均值就是node->val。
难道只能是：
```dfs(node, 1) = dfs(node->left, 1) + dfs(node->right, 1) + 0``` ？这个似乎更不可能呀。

其实这里的关键在于，dfs(node->left, 1) 的第二个参数必须是设置fixed，但是第一个参数其实是变动之后再fixed。什么意思呢？我把代码写一下：
```
node->left->val = node->val * 2 - node->val->right;
dfs(node, 1) = dfs(node->left, 1) + dfs(node->right, 1) + 1 （这个1不是因为node的变动，而是因为node->left的变动）
```
这样来看这个递归式子是不是合理了？我们根据node->val和node->right->val,计算出了期待的node->left->val，于是上面最后加上的那个0就有保障了。
同理我们还需要考虑另外一支：
```
node->right->val = node->val * 2 - node->val->left;
dfs(node, 1) = dfs(node->left, 1) + dfs(node->right, 1) + 1 （这个1不是因为node的变动，而是因为node->right的变动）
```
这样的话，dfs(node,1)就能够顺利递归下去了。注意，以上的操作改变了原生的树，回溯的时候记得要把改动的值都改回来。

有人可能会深入思考之后会问，有没有可能出现这样最优解来自的情况：
```
node->left->val = a;
node->right->val = b;  // a + b = node->val*2
dfs(node, 1) = dfs(node->left, 1) + dfs(node->right, 1) + 2 （如果新设定的node->left和node->right都和原生值不同）
```
事实上这是不可能得到最优解的。这个我没有办法很简洁地给出严谨解释，大致的感觉是那个2并不合算。（欢迎大家补充对这点的理解）

综上，整体的思路大致就结束了。其实上面分析其实有可以交错合并的枝节，但为了保证分类的严谨性，我都不厌其烦地列举出来了。

我整理一下伪代码。注意在处理左右子树是否为空的时候，还有很多细节，请自行处理。另外，相同的dfs可能会重复调用，加入记忆化的话会更高效。
```
pair{returnedNodeValue, minChanges} = dfs(node, fixed)
{
	boundary cases;

	if (fixed == 1)
	{
		leftFree = dfs(node->left, 0);
		rightFree = dfs(node->right, 0);
		leftFixed = dfs(node->left, 1);
		rightFixed = dfs(node->right, 1);

		// branch 1
		changes  = leftFree.second + rightFree.second + (node->val * 2 != leftFree.first + rightFree.first);
		returnedNodeValue = (leftFree.first + rightFree.first) / 2.0;

		// branch 2
		changes  = leftFixed.second + rightFree.second + (node->val * 2 != leftFree.first + rightFree.first);
		returnedNodeValue = (leftFree.first + rightFree.first) / 2.0;

		// branch 3
		changes  = leftFree.second + rightFixed.second + (node->val * 2 != leftFree.first + rightFree.first);
		returnedNodeValue = (leftFree.first + rightFree.first) / 2.0;

		return pickTheMinChangesFromTheAboveThree(returnedNodeValue, changes);		 
	}

	else if (fixed == 0)
	{
		// branch 1
		node->left->val = node->val * 2 - node->right->val;
		leftFixed = dfs(node->left, 1);
		rightFixed = dfs(node->right, 1);
		changes  = leftFixed.second + rightFixed.second + (node->val * 2 != leftFixed.first + rightFixed.first);
		returnedNodeValue = (leftFixed.first + rightFixed.first) / 2.0;
		recover(node->left); // backtrace

		// branch 2
		node->right->val = node->val * 2 - node->left->val;
		leftFixed = dfs(node->left, 1);
		rightFixed = dfs(node->right, 1);
		changes  = leftFixed.second + rightFixed.second + (node->val * 2 != leftFixed.first + rightFixed.first);
		returnedNodeValue = (leftFixed.first + rightFixed.first) / 2.0;
		recover(node->right); // backtrace

		return pickTheMinChangesFromTheAboveTwo(returnedNodeValue, changes);		 
	}
}
```
