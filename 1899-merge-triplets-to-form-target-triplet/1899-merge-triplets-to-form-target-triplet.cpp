class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // condition 1 : the triplets shouldnt have values more than target
        // condition 2 : the first condition is initial checking
        // so if the there are no values greater than the triplet
        // then we need to check that for every triplet at 0 th position, the max value is target[0]
        // same for 1, 2
        // if these two conditions pass then we can get the target triplet
        
        bool a = false, b = false, c = false;
        for(int i = 0; i < triplets.size(); i++){
            // maxTriplet[0] = max(maxTriplet[0], triplets[i][0]);
            // maxTriplet[1] = max(maxTriplet[1], triplets[i][1]);
            // maxTriplet[2] = max(maxTriplet[2], triplets[i][2]);
            // as we just need to form the target triplet with any of the given triplets , and not all 
            // so we can just make sure there exists a triplet with target triplet values
            // or is able to form target triplet value;

            if(triplets[i][0] == target[0]){
                if(triplets[i][1] == target[1] && triplets[i][2] == target[2]) return true;
                if(triplets[i][1] <= target[1] && triplets[i][2] <= target[2]){
                    a = true; 
                }
            }
            if(triplets[i][1] == target[1]){
                if(triplets[i][0] <= target[0] && triplets[i][2] <= target[2]){
                    b = true; 
                }
            }
            if(triplets[i][2] == target[2]){
                if(triplets[i][1] <= target[1] && triplets[i][0] <= target[0]){
                    c = true; 
                }
            }
        }

        return (a == true && b == true) && c == true;
    }
};