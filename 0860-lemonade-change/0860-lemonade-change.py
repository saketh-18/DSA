class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        five = ten = tonty = 0

        for i in range(0,len(bills)):
            if bills[i] == 5:
                five += 1;
            elif bills[i] == 10:
                if five >= 1:
                    five -= 1;
                    ten += 1;
                else:
                    return False;
            else:
                if five >= 3:
                    tonty += 1;
                    five -= 3;
                elif ten >= 1 and five >= 2:
                    tonty += 1;
                    five -= 2;
                    ten -= 1;
                else:
                    return False;
        return True;