class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<char> stk;
        int i = s.length() - 1;

        while (i >= 0) {
            // skip spaces
            if (s[i] == ' ') {
                i--;
                continue;
            }

            // push current word onto stack (in reverse, so it comes out forward)
            while (i >= 0 && s[i] != ' ') {
                stk.push(s[i]);
                i--;
            }

            // pop stack to build the word in correct order
            while (!stk.empty()) {
                ans += stk.top();
                stk.pop();
            }

            // add single space if more words remain
            if (!ans.empty() && i >= 0) {
                // peek ahead to see if there's another actual word left
                int j = i;
                while (j >= 0 && s[j] == ' ') j--;
                if (j >= 0) ans += ' ';
            }
        }

        return ans;
    }
};