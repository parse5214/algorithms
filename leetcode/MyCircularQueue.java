class MyCircularQueue {
    
  int front = -1;
  int rear = -1;
  int sz = 0;
  int[] q;
  
  public MyCircularQueue(int k) {
      sz = k;
      q = new int[k];
  }
  
  public boolean enQueue(int value) {
      if( (rear + 1) % sz == front ) return false;
      else if( front == -1 ) {
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
  
  public boolean deQueue() {
      if( front == -1) return false;
      else if( front == rear) {
          front = rear = -1;
          return true;
      }else {
          front = (front + 1) % sz;
          return true;
      }
  }
  
  public int Front() {
      return (front == -1)? -1:q[front];
  }
  
  public int Rear() {
      return (rear == -1)? -1:q[rear];
  }
  
  public boolean isEmpty() {
      return front == -1;
  }
  
  public boolean isFull() {
      return (rear +1) % sz == front;
  }
}

/**
* Your MyCircularQueue object will be instantiated and called as such:
* MyCircularQueue obj = new MyCircularQueue(k);
* boolean param_1 = obj.enQueue(value);
* boolean param_2 = obj.deQueue();
* int param_3 = obj.Front();
* int param_4 = obj.Rear();
* boolean param_5 = obj.isEmpty();
* boolean param_6 = obj.isFull();
*/