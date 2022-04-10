#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            long long pre = (ll)nums[i]+(ll)nums[i+1]+(ll)nums[i+2]+(ll)nums[i+3];
            long long post = (ll)nums[i]+(ll)nums[n-3]+(ll)nums[n-2]+(ll)nums[n-1];
            if(pre > target) break;
            if(post < target) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) 
                    continue;
                long long pre1=(ll)nums[i]+(ll)nums[j]+(ll)nums[j+1]+(ll)nums[j+2];
                long long post1=(ll)nums[i]+(ll)nums[j]+(ll)nums[n-2]+(ll)nums[n-1];
                if(pre1>target) 
                    break;
                if(post1<target) 
                    continue;
                int left=j+1,right=n-1;
                while(left<right)
                {
                    long long sum=(ll)nums[left]+(ll)nums[right]+(ll)nums[i]+(ll)nums[j];
                    if(sum<target) 
                        left++;
                    else if(sum>target) 
                        right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
    }
	
    
    

};