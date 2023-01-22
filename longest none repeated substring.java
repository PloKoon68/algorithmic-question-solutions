//leetcode finding the longest without repeating charactes substring of given string 

//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

//solved this problem using ascii char array. This way it processessis in o(1) when accessing elements.





class Solution {
  public int lengthOfLongestSubstring(String s) {
      if(s.length() == 0)
            return 0;
        if(s.length() == 1)
            return 1;

        int[] arr = new int[127];
        int st = 0, q = 1;
        int maxLen = 0, len = 0;

        arr[s.charAt(st)] = 1;

        while(q < s.length()) {
            len = 0;
            //if the remaining is already less then max len just pass
            if(s.length() - st < maxLen)
                break;

            //find the repeating char
            while(true) {
                if(q == s.length())
                    return (q - st > maxLen)? q - st: maxLen;
                if(arr[s.charAt(q)] == 0)
                    arr[s.charAt(q)] = ++q;
                else {



                    len = q - st;

                    while(st != arr[s.charAt(q)] - 1) {
                        arr[s.charAt(st)] = 0;
                        st++;
                    }
                    st++;

                    arr[s.charAt(q)] = ++q;
                    break;
                }
            }

            //set max len
            maxLen = maxLen < len? len: maxLen;


        }


        return maxLen;
  }
}
