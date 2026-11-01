class myStack {
    queue<int> q;
    int length = 0;
  public:

    void push(int x) {
        int n = q.size();
        q.push(x);
        length++;
        
        for(int i=0;i<n;i++){
            q.push(q.front());
            q.pop();
        }
        
    }

    void pop() {
        if(q.empty()) return;
        q.pop();
        length--;
    }

    int top() {
        if(q.empty()) return -1;
        else return q.front();
    
    }

    int size() {
        return length;
    }
};
