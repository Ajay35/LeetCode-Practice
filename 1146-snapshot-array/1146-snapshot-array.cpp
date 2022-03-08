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
        for(int i = 0; i < store[index].size(); i++)
        {
            if(store[index][i].first <= snap_id)
                ans = store[index][i].second;
            else
                break;
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