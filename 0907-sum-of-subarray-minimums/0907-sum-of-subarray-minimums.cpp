class Solution {
public:

    //prev smaller -> index store krra hu me isme
    vector<int> prevSmaller(vector<int>& arr){

        int n = arr.size();
        stack<int> st;
        vector<int>prev(n);

        for(int i=0; i<n; i++){

            if(st.empty())
                prev[i] = -1;
            else{
                while(!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();
                prev[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return prev;
    }

    //next smaller -> index store krra hu me isme
    vector<int> nextSmaller(vector<int>& arr){
        
        int n = arr.size();
        stack<int> st;
        vector<int> next(n);

        for(int i=n-1; i>=0; i--){

            if(st.empty())
                next[i] = n;
            else{
                while(!st.empty() && arr[st.top()] > arr[i])
                    st.pop();
                next[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return next;
    }

    int sumSubarrayMins(vector<int>& arr) {
        
        //next smaller and prev smaller nikalnege ge aapan, uske liye array lgega:
        vector<int> prev =  prevSmaller(arr);
        vector<int> next =  nextSmaller(arr);

        int n = arr.size();
        long long M = 1e9+7;
        long long  sum = 0;

        for(int i=0; i<n; i++){

            long long ps = i - prev[i]; //prev smaller
            long long ns = next[i] - i; //next smaller

            long long noOfWays = ps*ns;
            long long totalSum = noOfWays*arr[i];

            sum = (sum + totalSum) %M;
        }
        return sum;
    }
};