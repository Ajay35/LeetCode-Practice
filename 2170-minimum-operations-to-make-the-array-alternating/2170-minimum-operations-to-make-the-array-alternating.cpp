class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        map<int, int> evens, odds;
        for(int i = 0; i < n; i++)
        {
            if((i + 1) & 1)
                odds[nums[i]]++;
            else
                evens[nums[i]]++;
        }
        int even_pos = n / 2;
        int odd_pos = (n + 1) / 2;
        int ans = 1e9;
        vector<pair<int, int>> odd_seq, even_seq;
        for(auto it: odds)
        {
            odd_seq.push_back({it.second, it.first});
        }
        for(auto it: evens)
        {
            even_seq.push_back({it.second, it.first});
        }
        sort(begin(odd_seq), end(odd_seq));
        sort(begin(even_seq), end(even_seq));
        
        for(int i = 0; i < n; i++)
        {
            int x = nums[i];
            
            if((i + 1) & 1)
            {
                int p1 = odd_pos - odds[x];
                int even_sz = even_seq.size();
                // nos of evens..?
                even_sz--;
                bool sub = false;
                while(even_sz >= 0)
                {
                    if(even_seq[even_sz].second != x)
                    {
                        p1 += (even_pos - even_seq[even_sz].first);
                        sub = true;
                        break;
                    }
                    even_sz--;
                }
                if(!sub)
                    p1 += even_pos;
                ans = min(ans, p1);
                    
            }
            else
            {
                int p1 = even_pos - evens[x];
                int odd_sz = odd_seq.size();
                // nos of odds..?
                odd_sz--;
                bool sub = false;
                while(odd_sz >= 0)
                {
                    if(odd_seq[odd_sz].second != x)
                    {
                        p1 += (odd_pos - odd_seq[odd_sz].first);
                        sub = true;
                        break;
                    }
                    odd_sz--;
                }
                if(!sub)
                    p1 += odd_pos;
                ans = min(ans, p1);
            }
            
        }
        return ans;
    }
};