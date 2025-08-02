// C++
class MyQueue {
    stack<int> st;
public:
    MyQueue() {}

    void push(int x) {
        st.push(x);
    }

    int pop() {
        stack<int> temp;
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        int removed = temp.top();
        temp.pop();
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
        return removed;
    }

    int peek() {
        stack<int> temp;
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        int peek = temp.top();
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
        return peek;
    }

    bool empty() {
        return st.empty();
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