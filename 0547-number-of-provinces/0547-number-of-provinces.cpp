class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size() , 0);
        int province = 0;
        int n = isConnected.size();
        int i = 0;
        for(int j = 0 ; j < n ; j++){
            stack<int> st;
            if(visited[j] == 0){                
                st.push(j);
                visited[j] = 1;
            while(!st.empty()){
                int temp = st.top();
                st.pop();

                for(int i = 0 ; i < isConnected.size(); i++){
                    if(isConnected[temp][i] == 1 && visited[i] == 0){
                        st.push(i);
                        visited[i] = 1;
                    }
                }
            }
            province++;
        } 
    } 
        return province;
    }
};