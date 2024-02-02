//https://leetcode.com/problems/sequential-digits/description/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int num = low, numDigits = 0, start;

        int prev = 0;
        bool incFirst = false;
        while (num) {
            if (prev - num % 10 > 1)
                incFirst = true;
            else if (num % 10 >= prev)
                incFirst = false;

            if (num < 10)
                start = num;

            prev = num % 10;
            num /= 10;
            numDigits++;
        }
        if (incFirst)
            start++;

        if (start + numDigits - 1 > 9) {
            start = 1;
            numDigits++;
        }

        int startNum = 0, end = start + numDigits - 1;

        int i = 0, addition = 0;
        while (i < numDigits) {
            startNum *= 10;
            startNum += start + i++;

            addition *= 10;
            addition++;
        }

        ;


        int current = startNum;

        vector<int> result;

        while (current <= high) {
            while (end <= 9) {
                if (current > high)
                    return result;
                result.push_back(current);
                current += addition;
                end++;
            }

            addition *= 10;
            addition++;
            numDigits++;
            current = 0;

            int j = 0;
            while (j < numDigits) {
                current *= 10;
                current += ++j;

            }
            end = current % 10;

        }
        return result;
    }
};
