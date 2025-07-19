class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start = image[sr][sc];
        if(color == start) return image;
        queue<pair<int , int>> que;
        int rows = image.size();
        int cols = image[0].size();
        que.push({sr , sc});
        image[sr][sc] = color;
        
        while(!que.empty()){
            int r = que.front().first;
            int c = que.front().second;
            
            que.pop();
            vector<pair<int , int>> s = {{1,0},{-1,0},{0,1},{0,-1}};
            for(int i = 0 ; i < s.size(); i++){
                int nr = r + s[i].first;
                int nc = c + s[i].second;
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && image[nr][nc] == start){
                    image[nr][nc] = color;
                    que.push({nr,nc});
                    
                }
            }
        }
        return image;
    }
};