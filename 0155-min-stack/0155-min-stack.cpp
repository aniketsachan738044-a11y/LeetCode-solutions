class MinStack {
public:
    stack<long long> st;
    long long minVal;

    MinStack() { // constructor
        minVal = LLONG_MAX;
    }

    void push(int val) { // O(1)
        long long x = (long long)val;
        if (st.empty()) {
            st.push(x);
            minVal = x;
        }
        else if (x >= minVal) {
            st.push(x);
        }
        else { // x < minVal
            st.push(2 * x - minVal);
            minVal = x;
        }
    }

    void pop() { // O(1)
        if (st.top() < minVal) { // a fake/encoded value is present
            // before popping, recover the old min
            long long oldMin = 2 * minVal - st.top();
            minVal = oldMin;
        }
        st.pop();
    }

    int top() { // O(1)
        if (st.top() < minVal) return (int)minVal;
        else return (int)st.top();
    }

    int getMin() { // O(1)
        return (int)minVal;
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