//question:    https://leetcode.com/problems/maximum-swap/description/
//my solution: https://leetcode.com/problems/maximum-swap/solutions/5931474/o-n-c-easy-solution/

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> numIndex(10, 0);

        int numCopy = num, tenMultiple = 1;
        while (numCopy) {
            int mod = numCopy % 10;
            if (!numIndex[mod])
                numIndex[mod] = tenMultiple;

            numCopy /= 10;
            tenMultiple *= 10;
        }

        tenMultiple /= 10; 
        while (tenMultiple) {
            int j = 9;
            int swapLeft = (num / tenMultiple) % 10; //left digit
            while (j > swapLeft) { //search the numbers starting from 9 until the left digit number
                if (numIndex[j] && numIndex[j] < tenMultiple) {   //check if the digit of the number is on the right side of the number
                    //if found, return the number with its two digits swapped
                    return num + tenMultiple * (j - swapLeft) + numIndex[j] * (swapLeft - j);
                }
                j--;
                    //return returnVal(num, numIndex[j], i);
            }
            tenMultiple /= 10;
        }

        return num;
    }
};
