//https://leetcode.com/problems/generate-parentheses/description/

//generating valid paranthesis (every left paranthesis has an enclosing right paranthesis) based on the input n.


class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new LinkedList<>();
        process(0, 0, n, "", result);

        return result;
    }

    public void process(int left, int right, int n, String str, List<String> lst) {
        if(right == n && left  == n) {
            lst.add(str);
            return;
        }

        if(left < n)
            process(left + 1, right, n, str + "(", lst);
        if(right < left)
            process(left, right + 1, n, str + ")", lst);

    }
}
