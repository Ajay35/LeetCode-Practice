class Solution {
public:
    vector<int> pivotArray(vector<int>& A, int pivot) {
        vector<int> gt; 
        int j = 0, cnt = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] < pivot) A[j++] = A[i];
            else if (A[i] == pivot) ++cnt;
            else gt.push_back(A[i]);
        }
        while (cnt--) A[j++] = pivot;
        for (int i = 0; i < gt.size(); ++i) A[j++] = gt[i];
        return A;
    }
};