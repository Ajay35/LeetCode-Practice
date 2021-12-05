class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> freq(10), ans;
        for(int i = 0; i < digits.size(); i++)
                freq[digits[i]]++;
        for(int i = 100; i <= 999; i+=2)
        {
            vector<int> freq1(10);
            int t = i;
            while(t > 0)
            {
                int d = t % 10;
                freq1[d]++;
                t = t /10;
            }
            bool possible = true;
            for(int j = 0; j < 10; j++)
            {
                if(freq1[j] > 0 and freq1[j] > freq[j])
                {
                    possible = false;
                    break;
                }
            }
            if(possible)
                ans.push_back(i);
        }
        
    
        return ans;
    }
};