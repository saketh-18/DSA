class RandomizedSet {
public:
    vector<int> vec;
    unordered_map<int,int> mp;
    mt19937 gen;
    RandomizedSet() {
        random_device rd;
        gen = mt19937(rd());
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            vec.push_back(val);
            mp[val] = vec.size()-1;
            return true;
        } return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()){
            int idx = mp[val];
            int last = vec.back();
            swap(vec[mp[val]],vec[vec.size()-1]);
            mp[last] = idx;
            vec.pop_back();
            mp.erase(val);
            return true;
        } return false;
    }
    
    int getRandom() {

        uniform_int_distribution<> distrib(0, mp.size()-1); 
        return vec[distrib(gen)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */