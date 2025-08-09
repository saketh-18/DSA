class Solution {
public:
    int romanToInt(string s) {
        //traverse from left to right
        //if ab , a > b normal , if b > a then b - a

        unordered_map<char,int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;

        int ans = 0;
        for(int i = 0 ; i < s.length(); i++){
            if(i < s.length() - 1 && mpp[s[i]] < mpp[s[i+1]]){
                ans += (mpp[s[i+1]] - mpp[s[i]]);
                cout << mpp[s[i+1]] - mpp[s[i]] << endl;
                i++;
            }
            else ans += mpp[s[i]]; cout << mpp[s[i]] << endl;
        }
        return ans;
    }
};