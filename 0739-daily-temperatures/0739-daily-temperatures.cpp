class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--){
            if(st.empty())
                ans[i] = 0;
            else{
                while(!st.empty() && arr[st.top()] <= arr[i])
                    st.pop();
                ans[i] = st.empty() ? 0 : (st.top() - i);
            }
            st.push(i);
        }
        return ans;
    }
};