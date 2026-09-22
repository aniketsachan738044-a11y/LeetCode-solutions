class MinStack {
    stack<int> st;
    stack<int> helper;
public:
    MinStack() { // constructor
    }

    void push(int val) { // O(1)
        st.push(val);
        if (helper.empty() || val <= helper.top())
            helper.push(val);
        else
            helper.push(helper.top());
    }

    void pop() { // O(1)
        st.pop();
        helper.pop();
    }

    int top() { // O(1)
        return st.top();
    }

    int getMin() {
        return helper.top();
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */