class MinStack {
    vector<int> v;       // main stack
    vector<int> mins;    // tracks minimum at each stack level

public:
    MinStack() { }

    void push(int val) {
        v.push_back(val);
        if (mins.empty() || val <= mins.back())
            mins.push_back(val);
        else
            mins.push_back(mins.back());
    }

    void pop() {
        v.pop_back();
        mins.pop_back();
    }

    int top() {
        return v.back();
    }

    int getMin() {
        return mins.back();
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