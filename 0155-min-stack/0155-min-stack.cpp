class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        }
        else if (val >= mini) {
            st.push(val);
        }
        else {
            st.push(2LL * val - mini);
            mini = val;
        }
    }

    void pop() {
        if (st.empty()) return;

        long long x = st.top();
        st.pop();

        if (x < mini)
            mini = 2LL * mini - x;
    }

    int top() {
        if (st.empty()) return -1;

        long long x = st.top();

        if (x >= mini)
            return (int)x;

        return (int)mini;
    }

    int getMin() {
        return (int)mini;
    }
};