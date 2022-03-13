class Solution {
public:
    bool findResidualPath(int i, vector<unordered_map<int, int>> &al, vector<bool> &visited) {
        if (i == al.size() - 1)
            return true;
        for (auto [j, c] : al[i])
            if (c && !visited[j]) {
                visited[j] = true;
                swap(al[i][j], al[j][i]);
                if (findResidualPath(j, al, visited))
                    return true;
                swap(al[i][j], al[j][i]);
            }
        return false;
    }
    int maximumInvitations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<unordered_map<int, int>> al(m + n + 1);
        for (auto i = 0; i < m; ++i)
            for (auto j = 0; j < n; ++j)
                if (grid[i][j])
                    al[i].insert({j + m, 1});
        for (auto j = 0; j < n; ++j)
            al[j + m].insert({m + n, 1});
        int res = 0;
        for (auto i = 0; i < m; ++i)
            res += findResidualPath(i, al, vector<bool>(m + n + 1) = {});
        return res;
    }
};