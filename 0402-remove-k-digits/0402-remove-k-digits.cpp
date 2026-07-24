class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if (n == k)
            return "0";

        string stk = "";

        for (int i = 0; i < n; i++) {
            while (k > 0 && !stk.empty() && num[i] < stk.back()) {
                stk.pop_back();
                k--;
            }
            stk.push_back(num[i]);
        }

        while (k > 0) {
            stk.pop_back();
            k--;
        }

        int idx = 0;
        while (idx < (int)stk.size() - 1 && stk[idx] == '0')
            idx++;
        stk = stk.substr(idx);

        return stk.empty() ? "0" : stk;
    }
};