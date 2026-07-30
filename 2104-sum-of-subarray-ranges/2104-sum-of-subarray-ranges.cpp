class Solution {
public:

    //prev smaller
    vector<int> prevSmaller(vector<int>& nums){

        stack<int> st;
        int n = nums.size();
        vector<int> prev(n);

        for(int i=0; i<n; i++){

            if(st.empty())
                prev[i] = -1;
            else{
                while(!st.empty() && nums[st.top()] >= nums[i]){
                    st.pop();
                }
                prev[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return prev;
    }

    // next smaller
    vector<int> nextSmaller(vector<int>& nums){

        stack<int> st;
        int n = nums.size();
        vector<int> next(n);

        for(int i=n-1; i>=0; i--){

            if(st.empty())
                next[i] = n;
            else{
                while(!st.empty() && nums[st.top()] > nums[i]){
                    st.pop();
                }
                next[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return next;
    }

    //SUM OF MIN WAALA OF ALL SUBARRAY
    long long sumOfSubArrayMin(vector<int>& nums){

        // me kyoki yaha min ka sum calu karuga
        int n = nums.size();
        long long totalSum = 0;

        //tho mers prev and next min ke liye hai!
        vector<int> prev = prevSmaller(nums);
        vector<int> next = nextSmaller(nums);

        for(int i=0; i<n; i++){

            long long ls = i - prev[i];
            long long rs = next[i] - i;

            long long noOfWays = ls*rs;
            long long sum = noOfWays*nums[i];

            totalSum += sum;
        }
        return totalSum;
    }

    //PrevGreater ka block
    vector<int> prevGreater(vector<int>& nums){

        stack<int> st;
        int n = nums.size();
        vector<int> prev(n);

        for(int i=0; i<n; i++){

            if(st.empty())
                prev[i] = -1;
            else{
                while(!st.empty() && nums[st.top()] <= nums[i])
                    st.pop();

                prev[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return prev;
    }
    
    // nextGreater ka block
    vector<int> nextGreater(vector<int>& nums){

        stack<int> st;
        int n = nums.size();
        vector<int> next(n);

        for(int i=n-1; i>=0; i--){

            if(st.empty())
                next[i] = n;
            else{
                while(!st.empty() && nums[st.top()] < nums[i])
                    st.pop();

                next[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return next;
    }
    //SUM OF MAX WAALA BLOCK
    long long sumOfSubArrayMax(vector<int>& nums){
        
        long long sum = 0;
        int n = nums.size();
        vector<int> prev = prevGreater(nums);
        vector<int> next = nextGreater(nums);

        for(int i=0; i<n; i++){

            long long ls = i - prev[i];
            long long rs = next[i] - i;

            long long noOfWays = ls*rs;
            long long totalSum = noOfWays*nums[i];

            sum += totalSum;
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        
        long long small = sumOfSubArrayMin(nums);
        long long large = sumOfSubArrayMax(nums);

        return large - small; 
    }
};