//converting roman to integer
//https://leetcode.com/problems/roman-to-integer/description/

class Solution {
    public int romanToInt(String s) {
        HashMap<Character,Integer> mp = new HashMap<>();
        mp.put('I',1);
        mp.put('V',5);
        mp.put('X',10);
        mp.put('L',50);
        mp.put('C',100);
        mp.put('D',500);
        mp.put('M',1000);

        int sum = mp.get(s.charAt(s.length() - 1)), i = s.length() - 2;
        while(i >= 0) {
            sum += (mp.get(s.charAt(i)) >= mp.get(s.charAt(i + 1))) ? mp.get(s.charAt(i)) : -mp.get(s.charAt(i));
            i--;
        }

        return sum;
    }
}
