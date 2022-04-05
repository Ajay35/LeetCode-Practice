class Solution {
public:
    int smallestDistanceSum = INT_MAX;
    int visited[10];
    
    int findDistance(vector<int>& worker, vector<int>& bike) 
    {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    void minimumDistanceSum(vector<vector<int>>& workers, int workerIndex, 
                            vector<vector<int>>& bikes, int currDistanceSum) 
    {
        if (workerIndex >= workers.size()) {
            smallestDistanceSum = min(smallestDistanceSum, currDistanceSum);
            return;
        }

        if (currDistanceSum >= smallestDistanceSum) 
            return;
        
        for (int bikeIndex = 0; bikeIndex < bikes.size(); bikeIndex++) 
        {
            if (!visited[bikeIndex]) 
            {
                visited[bikeIndex] = true;
                minimumDistanceSum(workers, workerIndex + 1, bikes, 
                    currDistanceSum + findDistance(workers[workerIndex], bikes[bikeIndex]));
                visited[bikeIndex] = false;
            }
        }
        
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) 
    {
        minimumDistanceSum(workers, 0, bikes, 0);
        return smallestDistanceSum;
    }
};