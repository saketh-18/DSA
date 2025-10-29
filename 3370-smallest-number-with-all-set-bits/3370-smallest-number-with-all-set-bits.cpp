class Solution {
public:
    int smallestNumber(int n) {
        string binary = "";

        while(n > 0){
            binary = to_string(n%2) + binary;
            n /= 2;
        }

        for(int i = 0; i < binary.size(); i++){
            binary[i] = '1';
        }

        int decimal = stoi(binary,0,2);

        return decimal;
    }
};