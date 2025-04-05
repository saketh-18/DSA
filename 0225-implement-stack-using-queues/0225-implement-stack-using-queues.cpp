class MyStack {
public:
    queue<int> b;
    queue<int> a;
    int topel;
    MyStack() {
        
    }
    
    void push(int x) {
        b.push(x);
        topel = x;
    }
    
    int pop() {
        int n = b.size();
        for(int i = 0 ; i < n-1; i++){
            topel = b.front();
            a.push(b.front());
            b.pop();
        }

        int x =  b.front();
        b.pop();
        swap(a,b);
        return x;
        
    }
    
    int top() {
       return topel;
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