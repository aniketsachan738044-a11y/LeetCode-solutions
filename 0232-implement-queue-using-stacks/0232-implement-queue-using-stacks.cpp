class MyQueue {
public:
    stack<int> st;
    stack<int> helper;

    MyQueue() {}

    void push(int x) {
        // move everything to helper
        while (!st.empty()) {
            helper.push(st.top());
            st.pop();
        }
        // x goes to the bottom
        st.push(x);
        // move everything back on top of x
        while (!helper.empty()) {
            st.push(helper.top());
            helper.pop();
        }
    }

    int pop() {
        int x = st.top();
        st.pop();
        return x;
    }

    int peek() {
        return st.top();
    }

    bool empty() {
        return st.empty();
    }
};