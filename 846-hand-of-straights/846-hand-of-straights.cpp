class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();
        map<int, int> store;
        if(n % groupSize)
            return false;
        sort(begin(hand), end(hand));
        for(int i = 0; i < n; i++)
        {
            store[hand[i]]++;
        }
        
        for(auto it: store)
        {
            int num = it.first;
            int cnt = it.second;
            while(cnt > 0)
            {
                int cur = num + 1;
                for(int j = 1; j <= groupSize-1;j++)
                {
                    int cur = num + j;
                    if(store[cur] == 0)
                        return 0;
                    else
                        store[cur]--;
                }
                store[num]--;
                cnt--;
            }
        }
        
        return true;
    }
};