//1816. Truncate Sentence

class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.size();
        int end = 0, count = 0;
        for (int i = 1; i <= n; i++) {
            if (i == n || s[i] == ' ') {
                count++;
                if (count == k) {
                    end = i;
                    break;
                }
            }
        }
        return s.substr(0, end);
    }
};
