class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // first sorting
        // then frequency counting
        // then traversal and form groups
        // if at any point in the traversal , unable to form group then return true;
        if(hand.size() % groupSize != 0) return false;

        sort(hand.begin(), hand.end());
        unordered_map<int,int> hash;
        for(int i : hand){
            hash[i]++;
        }

        int groups = 0;
        for(int i = 0; i < hand.size(); i++){
            //star forming groups with the hand[i] as starting position
            if(hash[hand[i]] == 0) continue; //  its already taken in another group
            for(int k = 0; k < groupSize; k++){
                if(hash[hand[i] + k] <= 0){
                    return false;
                }
                hash[hand[i] + k]--;
            }
            groups++;
        }
        cout << groups;
        return groups == hand.size() / groupSize;
    }
};