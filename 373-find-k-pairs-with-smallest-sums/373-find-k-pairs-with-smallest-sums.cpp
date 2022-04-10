class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n=nums1.size(),m=nums2.size();
        if(n==0||m==0) return (ans);
        priority_queue<tuple<int,int, int>> pq;
        pq.push({-nums1[0]-nums2[0],0,0});   // insert initial pair in priority queue
        while(pq.size()&&ans.size()<k)       // pq.size() is necessary coz k can be larger than m*n
        {
            auto topp=pq.top();                // extracting smallest element from pq
            int i=get<1>(topp);
            int j=get<2>(topp);
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});   // insert smallest pair in ans vector
            if(j==0&&i+1<n) pq.push({-nums1[i+1]-nums2[j],i+1,j});   
			
            if(i<n&&j+1<m) pq.push({-nums1[i]-nums2[j+1],i,j+1});
        }
        return (ans);        
    }
};