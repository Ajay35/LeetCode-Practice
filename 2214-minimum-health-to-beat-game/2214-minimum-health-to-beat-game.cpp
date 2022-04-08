class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) 
    {
        return std::accumulate(damage.begin(), damage.end(), 0LL) -
            std::min(*std::max_element(damage.begin(), damage.end()), armor) + 1;
    }
};