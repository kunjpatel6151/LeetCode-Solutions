class MyQueue {
public:
    stack<int> first;
    stack<int> second;
    MyQueue() {
        
    }
    
    void push(int x) {
        first.push(x);
    }
    
    int pop() {
        if(second.empty()){
            while(!first.empty()){
                second.push(first.top());
                first.pop();
            }
        }
        if(!second.empty()){
            int front=second.top();
            second.pop();
            return front;
        }
        return -1;
    }
    
    int peek() {
        if(second.empty()){
            while(!first.empty()){
                second.push(first.top());
                first.pop();
            }
        }
        if(!second.empty()){
            int front=second.top();
            return front;
        }
        return -1;
    }
    
    bool empty() {
        return first.empty() && second.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */