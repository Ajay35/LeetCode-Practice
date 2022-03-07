class Solution {
public:
    int maximumInvitations(vector<int>& A) {
        int N = A.size();
        vector<int> m(N, -1); 
        vector<vector<int>> r(N); 
        for (int i = 0; i < N; ++i) r[A[i]].push_back(i);
        function<int(int)> dfs = [&](int u) {
            if (m[u] != -1) return m[u];
            int ans = 0;
            for (int v : r[u]) ans = max(ans, dfs(v));
            return m[u] = 1 + ans;
        };
        int ans = 0, free = 0;
        for (int i = 0; i < N; ++i) {
            if (m[i] != -1) continue;
            if (A[A[i]] == i) {
                m[i] = m[A[i]] = 0;
                int a = 0, b = 0; 
                for (int v : r[i]) {
                    if (v == A[i]) continue;
                    a = max(a, dfs(v));
                }
                for (int v : r[A[i]]) {
                    if (v == i) continue;
                    b = max(b, dfs(v));
                }
                free += a + b + 2;
            }
        }
        function<tuple<int, int, bool>(int)> dfs2 = [&](int u)->tuple<int, int, bool> {
            if (m[u] != -1) return {u, m[u], false}; 
            m[u] = 0;
            auto [entryPoint, depth, cycleVisited] = dfs2(A[u]);
            if (cycleVisited) { 
                return {entryPoint, depth, true};
            }
            m[u] = 1 + depth; 
            return {entryPoint, m[u], u == entryPoint}; 
        };
        for (int i = 0; i < N; ++i) {
            if(m[i] != -1) continue;
            auto [entryPoint, depth, cycleVisited] = dfs2(i);
            if (cycleVisited) ans = max(ans, depth);
        }
        return max(ans, free);
    }
};