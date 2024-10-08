//https://leetcode.com/problems/sentence-similarity-iii/description/?envType=daily-question&envId=2024-10-06

class Solution {
public:
    vector<string> splitString(const string& str) {
        vector<string> result;
        istringstream ss(str);
        string word;

        while (ss >> word) {
            result.push_back(word);
        }

        return result;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> wordsBig = sentence1.size() > sentence2.size() ? splitString(sentence1) : splitString(sentence2);
        vector<string> wordsSmall = sentence1.size() > sentence2.size() ? splitString(sentence2) : splitString(sentence1);


        int bi = 0, si = 0, be = wordsBig.size(), se = wordsSmall.size();
        int scp = -1;

        while (si < se) {
            if (bi == be) return false; //bigger sentence finished before small sentence finished
            if (wordsBig[bi] != wordsSmall[si]) {
                if (scp == -1)
                    scp = si;
                else si = scp;
                while (wordsBig[bi] != wordsSmall[si])
                    if (++bi == be) return false;  //bulamadan sona gelirse return false
            }
            bi++;
            si++;
        }

        //        if (scp == -1 && si >= se) return true;
        if (scp == -1) return true;

        if (scp != -1 && bi < be) {
            //son harfi sona kadar eşit
            while (bi < be) {
                if (wordsBig[bi] != wordsSmall[se - 1]) break;
                bi++;
            }
            if (bi == be) return true;

            //küçük olan sonda
            bi = be - 1;
            si = se - 1;
            while (si >= 0)
                if (wordsBig[bi--] != wordsSmall[si--]) return false;
            return true;
        }
        else return true;
    }
};
