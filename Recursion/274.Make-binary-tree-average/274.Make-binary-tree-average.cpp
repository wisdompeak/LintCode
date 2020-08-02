class Solution {
public:
    /**
     * @param root: the root
     * @return: return the min steps
     */
    int makeBinaryTreeAverage(TreeNode * root) {
        return dfs(root, false).second;
    }
    
    pair<float, int> dfs(TreeNode* node, int fixed)
    {
        if (node==NULL) return {-1, 0};
        if (!node->left && !node->right) return {node->val, 0};
        
        int minChanges = INT_MAX/2;
        int changes;
        float value, avg;
        
        if (fixed == 0)
        {            
            // all children are free            
            auto leftFree = dfs(node->left, 0);
            auto rightFree = dfs(node->right, 0);
            auto leftFixed = dfs(node->left, 1);
            auto rightFixed = dfs(node->right, 1);
            
            if (node->left && node->right) avg = (leftFree.first + rightFree.first)*0.5;
            else if (node->left) avg = leftFree.first;
            else avg = rightFree.first;
            changes = leftFree.second + rightFree.second + ((node->val == avg)?0:1);
            if (changes < minChanges)
            {
                minChanges = changes;
                value = avg;                
            }
            
            // left chid is free
            if (node->left && node->right) avg = (leftFree.first + node->right->val)*0.5;
            else if (node->left) avg = leftFree.first;
            else avg = node->right->val;
            changes = leftFree.second + rightFixed.second + ((node->val == avg)?0:1);
            if (changes < minChanges)
            {
                minChanges = changes;
                value = avg;                
            }
            
            // right chid is free
            if (node->left && node->right) avg = (node->left->val + rightFree.first)*0.5;
            else if (node->left) avg = node->left->val;
            else avg = rightFree.first;
            changes = leftFixed.second + rightFree.second + ((node->val == avg)?0:1);
            if (changes < minChanges)
            {
                minChanges = changes;
                value = avg;                
            }
        }
        else
        {
            // left child is free
            int leftVal;
            if (node->left && node->right) leftVal = node->val*2-node->right->val;                
            else if (node->left) leftVal = node->val;
            if (node->left)
            {
                float temp = node->left->val;
                node->left->val = leftVal;
                auto leftFixed = dfs(node->left, 1);
                auto rightFixed = dfs(node->right, 1);
                changes = leftFixed.second + rightFixed.second + ((leftVal==temp)?0:1);
                if (changes < minChanges) minChanges = changes;                                    
                node->left->val = temp;
            }            
            
            // right child is free
            int rightVal;
            if (node->left && node->right) rightVal = node->val*2-node->left->val;
            else if (node->right) rightVal = node->val;
            if (node->right)
            {
                float temp = node->right->val;
                node->right->val = rightVal;
                auto leftFixed = dfs(node->left, 1);
                auto rightFixed = dfs(node->right, 1);
                
                changes = leftFixed.second + rightFixed.second + ((rightVal==temp)?0:1);
                if (changes < minChanges) minChanges = changes;
                node->right->val = temp;                
            }    
            
            value = node->val;            
        }
        
        return {value, minChanges};
    }
};


