
//https://leetcode.com/problems/design-add-and-search-words-data-structure/


class WordDictionary {
public trie root;
    trie current;

    public WordDictionary() {
        this.root = new trie();
        this.current = root;
    }

    public void addWord(String word) {
        trie current = root;
        int i;
        for(i = 0; i < word.length(); i++) {
            if(current.childerens[(int)word.charAt(i) -97] == null)
                current.childerens[(int) word.charAt(i) - 97] = new trie();
            current = current.childerens[(int)word.charAt(i) -97];

        }
        current.isEnd = true;
        current = root;
    }

    public boolean search(String word) {


        int i;
        for(i = 0; i < word.length(); i++) {
            if(word.charAt(i) != '.') {
                if (current.childerens[(int) word.charAt(i) - 97] == null) {
                    this.current = root;
                    return false;
                }
                current = current.childerens[(int) word.charAt(i) - 97];
            }
            else {
                int j;
                for(j = 0; j < 26; j++) {
                    if(current.childerens[j] != null) {
                        //generate the sub word
                        String subWord = Character.toString((char)(j + 97)) + word.substring(i+1);
                        if(search(subWord)) {current = root; return true;}
                    }
                }
                if(j == 26) return false;
                break;
            }
        }
        return current.isEnd;
    }
}
class trie {
    trie[] childerens = new trie[26];
    boolean isEnd = false;
    trie() {};
}



/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
