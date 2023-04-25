//https://leetcode.com/problems/palindrome-number/



class Solution {
     public boolean isPalindrome(int x) {
        if(x < 0)
            return false;

        String num = Integer.toString(x);

        int ind = 0;
        char ch1 = num.charAt(0);
        while(ind < num.length() / 2) {
            if (num.charAt(ind) != num.charAt(num.length() - 1 - ind++))
                return false;
            
        }
        return true;
    }
}
