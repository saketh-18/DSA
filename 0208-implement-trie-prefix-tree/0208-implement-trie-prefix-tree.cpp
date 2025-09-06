class Trie {
public:
    unordered_map<string,int> pre;
    unordered_map<string,int> store;
    Trie() {
        
    }
    
    void insert(string word) {
        store[word]++;
        for(int i = 1; i <= word.length(); i++){
            string prefix = word.substr(0,i);
            pre[prefix]++;
        }
    }
    
    bool search(string word) {
        if(store.find(word) != store.end()) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        if(pre.find(prefix) != pre.end()) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */