class Solution {
public:

    void rev(vector<int>& s, int l, int r)
    {
        while (l < r)
            swap(s[l++], s[r--]);
    }
    int bsearch(vector<int>& s, int l, int r, int key)
    {
        int index = -1;
        while (l <= r) 
        {
            int mid = l + (r - l) / 2;
            if (s[mid] <= key)
                r = mid - 1;
            else 
            {
                l = mid + 1;
                if (index == -1 || s[index] >= s[mid])
                    index = mid;
            }
        }
        return index;
    }
    void nextPermutation(vector<int>& s) {
        int len = s.size(), i = len - 2;
        while (i >= 0 && s[i] >= s[i + 1])
            --i;
        if (i < 0)
        {
            sort(begin(s), end(s));
            return;
        }
        else 
        {
            int index = bsearch(s, i + 1, len - 1, s[i]);
            swap(s[i], s[index]);
            rev(s, i + 1, len - 1);
        }
    }
};