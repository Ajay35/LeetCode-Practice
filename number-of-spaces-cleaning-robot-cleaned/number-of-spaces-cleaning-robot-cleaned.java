class Solution {
    
    private int result = 0;
    private int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    public int numberOfCleanRooms(int[][] room) {
        
        int m = room.length;
        int n = room[0].length;
        boolean[][][] map = new boolean[4][m][n];
        boolean[][] visited = new boolean[m][n];
        dfs(room, 0, 0, 0, visited, map);
        return result;
    }
    
    private void dfs(int[][] room, int i, int j, int dir, boolean[][] visited, boolean[][][] map) {
        if (map[dir][i][j]) {
            return;
        }
        map[dir][i][j] = true;
        if (!visited[i][j]) {
            this.result++;
            visited[i][j] = true;
        }
        int[] move = dirs[dir];
        int nextI = i + move[0];
        int nextJ = j + move[1];
        if (nextI < 0 || nextI == room.length || nextJ < 0 || nextJ == room[0].length || room[nextI][nextJ] == 1) {
            dfs(room, i, j, (dir + 1) % 4, visited, map);
        } else {
            dfs(room, nextI, nextJ, dir, visited, map);
        }
    }
}