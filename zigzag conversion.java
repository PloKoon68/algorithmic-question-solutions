//converting a string to its zigzag verion
//https://leetcode.com/problems/zigzag-conversion/description/


class Solution {
     public String convert(String s, int numRows) {
        int ind = 0,i, k = 2 * numRows - 2;
        char[] word = new char[s.length()];
        if(numRows == 1)
            return s;


        for(int row = 0; row < numRows; row++) {
            i = 0;
            while(i < s.length() && ind < s.length() && i + row < s.length()) {
                if(row == 0) {
                    word[ind++] = s.charAt(i);
                }
                else if(row == numRows - 1) {
                    word[ind++] = s.charAt(i + row);
                }
                else {
                    word[ind++] = s.charAt(i + row);
                        if(i + k - row < s.length())
                            word[ind++] = s.charAt(i + k - row);
                        else
                            break;
                }
                i += k;
            }
            if(ind >= s.length())
                break;
        }

        return String.valueOf(word);
    }
          
}
