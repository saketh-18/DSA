class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int change = image[sr][sc];
        if(color == change) return image;
        int rows = image.size();
        int cols = image[0].size();
        queue<pair<int,int>> que;
        que.push({sr , sc});
        image[sr][sc] = color;

        while(!que.empty()){
            int r = que.front().first;
            int c = que.front().second;
            que.pop();
            
            vector<pair<int , int>> dir = {{1,0} , {-1,0} , {0,1} , {0,-1}};

            for(int i = 0 ; i < dir.size(); i++){
                int nr = r + dir[i].first;
                int nc = c + dir[i].second;

                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && image[nr][nc] == change){
                    image[nr][nc] = color;
                    que.push({nr , nc});
                }
            }
        }
        return image;
    }
};