class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string , int>> q;
        q.push({beginWord , 1});
        set<string> st;
        for(auto i : wordList){
            st.insert(i);
        }

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord) return steps;
            for(int i = 0; i < word.length(); i++){
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(st.find(word) != st.end()) {
                        q.push({word , steps + 1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }

        }
        return 0; 
    }
};