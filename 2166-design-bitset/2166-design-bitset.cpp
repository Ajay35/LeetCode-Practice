class Bitset {
public:
    vector<int> a, fli;
    int cnt = 0;
    int flip_cnt = 0;
    
    Bitset(int size) 
    {
        a.resize(size);
        fli.resize(size);
    }
    
    void fix(int idx) {
        
        if((flip_cnt - fli[idx]) & 1)
        {
            a[idx] = 1 - a[idx];
            fli[idx] = flip_cnt;
        }
        if(a[idx] == 0)
            cnt++;
        a[idx] = 1;
    }
    
    void unfix(int idx) 
    {
        if((flip_cnt - fli[idx]) & 1)
        {
            a[idx] = 1 - a[idx];
            fli[idx] = flip_cnt;
        }
        if(a[idx] == 1)
            cnt--;
        a[idx] = 0;
    }
    
    void flip() {
        cnt = a.size() - cnt;
        flip_cnt++;
    }
    
    bool all() {
        return cnt == a.size();
    }
    
    bool one() {
        return cnt >= 1;
    }
    
    int count() {
        
        return cnt;
    }
    
    string toString() {
        string ret;
        for(int i = 0; i < a.size(); i++)
        {
            int b = -1;
            if((flip_cnt - fli[i]) & 1)
                b = 1 - a[i];
            
            else
                b = a[i];
          
            ret.push_back((char)(b + '0'));
        }
        return ret;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */