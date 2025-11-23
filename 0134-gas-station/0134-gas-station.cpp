class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff(gas.size());
        int gasSum = 0, costSum = 0;
        for(int i = 0; i < gas.size(); i++){
            diff[i] = gas[i] - cost[i];
            gasSum += gas[i];
            costSum += cost[i];
        }
        if(costSum > gasSum) return -1;

        int sum = 0, start = 0;
        for(int i = 0; i < diff.size(); i++){
            if(sum < 0){
                sum = 0;
                start = i;
            }
            sum += diff[i];
        }
        return start;
    }
};