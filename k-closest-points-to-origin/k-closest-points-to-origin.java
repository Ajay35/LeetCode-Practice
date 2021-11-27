class Solution {
    public int[][] kClosest(int[][] points, int k) {
        Queue<int[]> maxPQ = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int i = 0; i < points.length; i++) {
            int[] entry = {squaredDistance(points[i]), i};
            if (maxPQ.size() < k) {
                maxPQ.add(entry);
            } else if (entry[0] < maxPQ.peek()[0]) {
               
                maxPQ.poll();
                maxPQ.add(entry);
            }
        }
        
        int[][] answer = new int[k][2];
        for (int i = 0; i < k; i++) {
            int entryIndex = maxPQ.poll()[1];
            answer[i] = points[entryIndex];
        }
        return answer;
    }
    
    private int squaredDistance(int[] point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};