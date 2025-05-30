class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    int minVal = INT_MAX;
    MinStack() {
         
    }
    
    void push(int val) {
        st.push(val);
        minVal = min(minVal , val);
        minSt.push(minVal);
    }
    
    void pop() {
        minSt.pop();
        st.pop();
        minVal = !minSt.empty() ? minSt.top() : INT_MAX;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */