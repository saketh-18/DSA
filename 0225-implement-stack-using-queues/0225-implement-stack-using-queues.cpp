class MyStack {
public:

    queue<int> s;
    queue<int> a;

    MyStack() {
        
    }
    
    void push(int x) {
        s.push(x);

        while(!a.empty()){
            s.push(a.front());
            a.pop();
        }

        swap(s,a);
    }
    
    int pop() {
        int x = a.front();
        a.pop();
        return x;
    }
    
    int top() {
        return a.front();
    }
    
    bool empty() {
        return a.empty();
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