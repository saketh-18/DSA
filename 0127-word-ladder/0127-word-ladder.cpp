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
                string original = word;
                for(int j = 0 ; j < 26; j++){
                    word[i] = j + 97;
                    auto it = st.find(word);
                    if(it != st.end()){
                        st.erase(word);
                        q.push({word , steps + 1});
                    }
                }
                word = original;
            }

        }
        return 0; 
    }
};