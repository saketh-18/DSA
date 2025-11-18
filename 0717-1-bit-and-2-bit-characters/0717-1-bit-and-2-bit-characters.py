class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        bit = False
        single = False
        for i in range(0,len(bits)):
            if(bit):
                bit = not bit
                single = False
            elif(bits[i] == 1): bit = True # means we're in the middle of scanning a special character
            else:
                single = True

        return single