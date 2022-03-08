class SnapshotArray {
public:
    int snaps;
    vector<pair<int, int>> store[50001];
    
    SnapshotArray(int length) {
        snaps=0;
    }
    
    void set(int index, int val) {
        store[index].push_back({snaps, val});
    }
    
    int snap() {
        snaps++;
        return snaps-1;
    }
    
    int get(int index, int snap_id) {
        // get the snapshot at index which is smaller or equal to
        // snap_id but not greater than snap_id....
        int ans = 0;
        int l = 0, r = store[index].size()-1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(store[index][mid].first > snap_id)
                r = mid-1;
            else if(store[index][mid].first <= snap_id) {
                ans = store[index][mid].second;
                l = mid + 1;
            }
        }
        return ans;
        
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */