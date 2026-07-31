class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        
        int pse = 0;
        int nse = 0;
        stack<int> st;
        int n = arr.size();
        int maxArea = 0;

        for(int i=0; i<n; i++){

            while(!st.empty() && arr[st.top()] > arr[i]){

                int element = st.top();
                st.pop();

                //element -> current waale ka area calculate hoga ele se
                //nse and pse upadte krna hai
                nse = i; //WHY!? -> next smaller bana, isiliye hi tho pop kiya hai upar!!
                pse = st.empty() ? -1 : st.top();

                maxArea = max((arr[element] * (nse - pse-1)), maxArea);
            }
            st.push(i);
        }

        while(!st.empty()){

            nse = n;
            int element = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, (nse - pse -  1) * arr[element]);
        }
        return maxArea;
    }
};