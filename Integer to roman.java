//converting integers from 1 to 3999 to roman number.
//https://leetcode.com/problems/integer-to-roman/description/

//converting roman to integer
//https://leetcode.com/problems/roman-to-integer/description/


class Solution {
     public String intToRoman(int num) {
        char[] priority = {'I','V','X', 'L', 'C','D', 'M'};
        StringBuffer roman = new StringBuffer();

        int i = 0;
        while(num > 0) {
            int mod = num % 10;

            if(mod <= 3)
                for(int j = 0; j < mod; j++)
                    roman.insert(0, priority[i]);
            else if(mod <= 8) {
                if(mod == 4) {
                    roman.insert(0, priority[i+1]);
                    roman.insert(0, priority[i]);
                }
                else {
                    for(int j = 0; j < mod - 5; j++)
                        roman.insert(0, priority[i]);
                    roman.insert(0, priority[i + 1]);
                }
            }
            else {
                roman.insert(0, priority[i + 2]);
                roman.insert(0, priority[i]);
            }

            num /= 10;
            i += 2;
        }



        return  roman.toString();
    }
}
