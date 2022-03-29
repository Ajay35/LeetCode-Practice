class Solution {
public:
    int confusingNumberII(int N) 
    {
        string s = to_string(N);
        vector<string> pairs = {"00", "11", "88", "69", "96"};
        unordered_map<int, vector<string>> level;
        level[0] = {""};
        unordered_set<long> cache;
        for (int m = 1; m <= s.size(); m++) 
        {
            if (m == 1)
                level[m] = {"0", "1", "8"};
            else {
                for (string mid : level[m - 2])
                for (string p : pairs)
                    level[m].push_back(p[0] + mid + p[1]);
            }
            for (string t : level[m]) {
                if (t[0] == '0') 
                    continue;
                long n = stol(t);
                if (n <= N) cache.insert(n);
            }
        }
		// The minus 1 is to get rid of 0
        return helper(s) - 1 - cache.size();
    }
private:
	// count number with digits in "01689" from 0 to s
    int helper(string s) {
        string digits = "01689";
        if (s.size() == 1) {
            int ret = 0;
            for (char c : digits) ret += c <= s[0];
            return ret;
        } else {
            int smaller = 0;
            for (char c : digits) smaller += c < s[0];
            int ret = smaller * powl(5, s.size() - 1);
            if (digits.find(s[0]) != string::npos)
                ret += helper(to_string(stol(s.substr(1))));
            return ret;
        }
    }
};