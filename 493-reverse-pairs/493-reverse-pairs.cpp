class FenwickTree {
public:
    FenwickTree(int n): sums(n+1, 0) {}
    
    void update(int i, int delta) {
        while (i < sums.size()) {
            sums[i] += delta;
            i += lowbit(i);
        }
    }
    
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += sums[i];
            i -= lowbit(i);
        }
        return sum;
    }
    
private:
    vector<int> sums;
    static inline int lowbit(int x) {
        return x & (-x);
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        vector<long> nums2;
        for (long num : nums) {
            nums2.push_back(2*num);
        }
        
		// combine nums and nums2, remove duplicates, then sort
        set<long> sorted;
        sorted.insert(nums.begin(), nums.end());
        sorted.insert(nums2.begin(), nums2.end());
        
		// map original nums to range [1, sorted.size()]
        int rank = 0;
        unordered_map<long, int> ranks;
        for (long num : sorted) {
            ranks[num] = ++rank;
        }
        
        FenwickTree tree(ranks.size());
        
        int res = 0;
        
		// from right to left, because we want to find how many nums are smaller than 1/2 of current num on the right
        for (int i = static_cast<int>(nums2.size())-1; i >= 0; --i) {
            res += tree.query(ranks[nums2[i] / 2] - 1);
            tree.update(ranks[nums2[i]], 1);
        }
        
        return res;
    }
};