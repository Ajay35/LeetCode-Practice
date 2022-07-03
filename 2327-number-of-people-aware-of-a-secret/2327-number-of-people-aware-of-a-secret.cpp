class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {  
        
        map<int, long long> delay_map;
        map<int, long long> forget_map;
        int mod = 1000000007;
        delay_map[1 + delay] = 1;
        forget_map[1 + forget] = 1;
        long long people_know = 1l, people_share = 0l;
        
        for(int i = 1; i <= n;)
        {
            if (i <= delay) 
            {
                i++;
                continue;
            }
            
            long long people_forget = forget_map[i];
            people_know -= people_forget;
            people_share -= people_forget;
            people_share += delay_map[i];
            delay_map[i + delay] = people_share % mod;
            forget_map[i + forget] = people_share % mod;
            people_know += people_share;
            i++;
        }
        return (int) (people_know % mod);
    }
};