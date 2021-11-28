class Solution {
    public int maxPoints(int[][] points) {
        if(points.length < 2) return points.length;
		int pointCount = points.length;
		int globalMaxCount = 1;
		Map<Double, Integer> hm = new HashMap<Double, Integer>();
		for(int i = 0; i < pointCount; i++){
			hm.clear();
			int samePointCount = 0;
			double slope;
			int maxCount = 0;
			for(int j = i + 1; j < pointCount; j++){
				if(points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
					samePointCount++;
					continue;
				} else if(points[i][0] == points[j][0] && points[i][1] != points[j][1]){
					slope = Double.MAX_VALUE;
				} else if(points[i][1] == points[j][1]){
					slope = 0;
				} else {
					slope = (double)(points[i][1] - points[j][1]) / (double)(points[i][0] - points[j][0]);
				}
				
				if(hm.containsKey(slope)){
					int tmp = hm.get(slope) + 1;
					hm.put(slope, tmp);

					if(tmp > maxCount) maxCount = tmp;

				} else {
					hm.put(slope, 1);
					if(maxCount == 0) maxCount = 1;
				}

			} // end inside for loop

			if(globalMaxCount < maxCount + samePointCount + 1) globalMaxCount = maxCount + samePointCount + 1;
			
		} // end outside for loop
		
		return globalMaxCount;
    }
}