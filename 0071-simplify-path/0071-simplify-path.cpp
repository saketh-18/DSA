class Solution {
public:
    string simplifyPath(string path) {
        string ans = "/";
        stack<string> st;
        stack<string> aux;
        for(int i = 0; i < path.length();i++){
            if(path[i] == '/'){
                i++;
                int cur = i;
                while(i < path.length() && path[i] != '/'){
                    i++;
                }
                // cout << cur << i << endl;
                string a = path.substr(cur,i-cur);
                if(a.length() > 0 && a != "."){
                    st.push(a);
                }
                if(path[i] == '/') i--;
            }
        }

        // while(!st.empty()){
        //     cout << st.top() << endl;
        //     st.pop();
        // }

        int over = 0;
        while(!st.empty()){
            if(st.top() == ".."){
                int i = 0;
                while(!st.empty() && st.top() == ".."){
                    st.pop();
                    i++;
                }
                while(!st.empty() && i > 0 && st.top() != ".."){
                    st.pop();
                    i--;
                }
                over += i;
            } else {
                if(over > 0){
                    while(!st.empty() && over > 0 && st.top() != ".."){
                        st.pop();
                        over--;
                    }
                } else {
                    aux.push(st.top());
                    st.pop(); 
                }
            }
        }

        // while(!aux.empty()){
        //     cout << aux.top() << endl;
        //     aux.pop();
        // }

        while(!aux.empty()){
            ans += aux.top();
            aux.pop();
            if(!aux.empty()) ans += '/';
        }
        
        return ans;
    }
};