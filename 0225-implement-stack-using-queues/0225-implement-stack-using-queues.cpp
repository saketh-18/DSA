class MyStack {
public:
    deque<int> b;
    MyStack() {
        
    }
    
    void push(int x) {
        b.push_back(x);
    }
    
    int pop() {
        int x = b.back();
        b.pop_back();
        return x;


    }
    
    int top() {
       return b.back();
    }
    
    bool empty() {
        return b.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */