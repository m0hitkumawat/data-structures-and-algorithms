class Solution {
public:
    int minAddToMakeValid(string s) {
        int length = 0;
        stack<char> stk;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push('(');
            } 
            else { // s[i] == ')'
                if (!stk.empty()) {
                    stk.pop();
                } else {
                    length++;
                }
            }
        }

        // Remaining '(' need matching ')'
        return length + stk.size();
    }
};