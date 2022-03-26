class Solution {
public:
    int largestBSTSubtree(TreeNode* root) 
    {
        int res = 0, minVal = INT_MIN, maxVal=INT_MAX;
        largestBSTSubtreeUtil(root, res, minVal, maxVal);
        return res;
    }
    
private:
    bool largestBSTSubtreeUtil(TreeNode* root, int& res, int& minVal, int& maxVal)
    {
        if(root == nullptr)
            return true;
        
        int lminVal=INT_MIN, lmaxVal=INT_MAX, lcount=0;
        bool left = largestBSTSubtreeUtil(root->left, lcount, lminVal, lmaxVal);
        
        int rminVal=INT_MIN, rmaxVal=INT_MAX, rcount=0;    
        bool right = largestBSTSubtreeUtil(root->right, rcount, rminVal, rmaxVal);
        
        if(left && right)
        {
            if((root->left == nullptr || root->val > lmaxVal) && (root->right == nullptr || root->val < rminVal)){
                res = lcount + 1 + rcount;
                minVal = root->left ? lminVal : root->val;
                maxVal = root->right ? rmaxVal : root->val;
                return true;
            }
        }
        
        res = max(lcount, rcount);
        return false;
    }
};