//https://leetcode.com/problems/implement-trie-prefix-tree/description/?envType=study-plan-v2&envId=leetcode-75


class Trie {
public:
    struct Node {
        char val;
        bool isEnd = false;
        unordered_map<char, Node*> trie;
    };
    Node* root;

    Trie() {
       this->root = new Node;
    }

    void insert(string word) {
        Node* node = this->root;

        for (char ch : word) {
            auto it = node->trie.find(ch);
            
            //if next char is not find, add it to the childs and set its val to the current char
            if (it == node->trie.end()) {
                node->trie[ch] = new Node();
                node = node->trie[ch];
                node->val = ch;
            }
            //if found, go to next char directly (already added)
            else 
                node = node->trie[ch];
        }
        
        node->isEnd = true;
    }

    bool search(string word) {
        Node* node = this->root;
        
        for (char ch : word) {
            auto it = node->trie.find(ch);

            //current char is not found in childs
            if (it == node->trie.end())
                return false;
            //next char found, go to next char 
            else 
                node = node->trie[ch];
        }
        return node->isEnd;
    }
    

    bool startsWith(string prefix) {
        Node* node = this->root;

        for (char ch : prefix) {
            auto it = node->trie.find(ch);

            //current char is not found in childs
            if (it == node->trie.end())
                return false;
            //next char found, go to next char 
            else
                node = node->trie[ch];
        }
        return true;
    }
};
