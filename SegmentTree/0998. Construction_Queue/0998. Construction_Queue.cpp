class Solution {
    class SegNode
    {
        public:
        SegNode* left;
        SegNode* right;
        int a,b;
        int status;
        SegNode(int _a, int _b)
        {
            a = _a;
            b = _b;
            status = b-a;
            if (a+1!=b)
            {
                int mid = (b-a)/2+a;
                left = new SegNode(a,mid);
                right = new SegNode(mid,b);
            }
            else
            {
                left = NULL;
                right = NULL;
            }
        }
    };
    
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
    
public:
    /**
     * @param n: The array sum
     * @param arr1: The size
     * @param arr2: How many numbers small than itself 
     * @return: The correct array
     */
    vector<int> getQueue(int n, vector<int> &arr1, vector<int> &arr2) 
    {
        vector<pair<int,int>>q;
        for (int i=0; i<arr1.size(); i++)
            q.push_back({arr1[i],i});
        sort(q.begin(),q.end());
        
        int N = arr1.size();
        SegNode* root = new SegNode(0,N);
        
        vector<int>results(N,0);
        for (int i=N-1; i>=0; i--)
        {
            int count = 0;
            int id = q[i].second;
            int ZeroNums =  arr2[id]+1;
            int j = FindKthZero(root,ZeroNums);
            results[j] = arr1[id];
        }
        
        return results;
    }
};
