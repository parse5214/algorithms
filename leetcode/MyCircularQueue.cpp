class MyCircularQueue {
public:
    int front = -1;
    int rear = -1;
    int sz = 0;
    vector<int> q;
    MyCircularQueue(int k) {
        sz = k;
        q.resize(sz);
    }
    
    bool enQueue(int value) {
        if( (rear + 1) % sz == front) return false;
        else if(front == -1) {
            front = 0;
            rear = 0;
            q[rear] = value;
            return true;
        }else {
            rear = (rear + 1) % sz;
            q[rear] = value;
            return true;
        }
        
    }
    
    bool deQueue() {
        if( front == -1 ) return false;
        else if( front == rear) {
            front = rear = -1;
            return true;
        }else {
            front = (front + 1) % sz;
            return true;
        }
    }
    
    int Front() {
        return (front == -1)? -1:q[front];
    }
    
    int Rear() {
        return (rear == -1)? -1:q[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % sz == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */