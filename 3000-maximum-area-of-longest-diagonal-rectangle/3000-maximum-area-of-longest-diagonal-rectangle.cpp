#include <cmath>
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int dia = 0, area = 0;
        for(int i = 0; i < dimensions.size(); i++){
            int a = dimensions[i][0];
            int b = dimensions[i][1];
            if(dia < (a*a + b*b)){
                dia = a*a + b*b;
                area = a*b;
            } else if(dia == (a*a + b*b)) {
                area = max(area,a*b);
            }

        }
        return area;
    }
};