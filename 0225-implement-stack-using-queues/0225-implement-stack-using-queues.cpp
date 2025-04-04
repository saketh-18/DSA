class MyStack {

    queue<int> mainQueue;
    queue<int> helperQueue;


public:
    MyStack() {
        
    }
    
    void push(int x) {
        mainQueue.push(x);
    }
    
    int pop() {
        int n = mainQueue.size();
        if (n == 0) {
            return -1;
        }

        for (int index = 1; index <= n - 1; index++) {
            helperQueue.push(mainQueue.front());
            mainQueue.pop();
        }

        int targetEle = mainQueue.front();
        mainQueue.pop();

        swap(mainQueue, helperQueue);
        return targetEle;
    }
    
    int top() {
        int n = mainQueue.size();
        if (n == 0) {
            return -1;
        }

        for (int index = 1; index <= n - 1; index++) {
            helperQueue.push(mainQueue.front());
            mainQueue.pop();
        }

        int targetEle = mainQueue.front();
        mainQueue.pop();
        helperQueue.push(targetEle);

        swap(mainQueue, helperQueue);
        return targetEle;
    }
    
    bool ``empty() {
        return mainQueue.size() == 0;
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