class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
    list<int> l(begin(nums), end(nums));
    for (auto it = begin(l); it != end(l); ++it)
        if (prev(it) != end(l)) {
            int n1 = *prev(it), n2 = *it;
            int it_gcd = gcd(n1, n2);
            if (it_gcd > 1) {
                l.erase(prev(it));
                *it = (long long)n1 * n2 / it_gcd;
                --it;
            }
        }
    return vector<int>(begin(l), end(l));}
};