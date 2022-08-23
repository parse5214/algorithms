class MyLinkedList {
    
    class Node {
        int val;
        Node next;
        public Node(int val, Node next) {
            this.val = val;
            this.next = next;
        }
    }
    
    Node head = null;
    Node tail = null;

    public MyLinkedList() {
        
    }
    
    public int get(int index) {
        Node tmp = head;
        while(index-- > 0 && tmp != null) tmp = tmp.next;
        if(tmp == null) return -1;
        return tmp.val;
    }
    
    public void addAtHead(int val) {
        Node tmp = new Node(val, null);
        if(head == null) {
            head = tail = tmp;
            return;
        }
        tmp.next = head;
        head = tmp;
    }
    
    public void addAtTail(int val) {
        Node tmp = new Node(val, null);
        if(head == null) {
            head = tail = tmp;
            return;
        }
        tail.next = tmp;
        tail = tmp;
    }
    
    public void addAtIndex(int index, int val) {
        Node prev = new Node(-1, null);
        Node tmp = head;
        int initial = index;
        while(index-- > 0 && tmp != null) {
            prev = tmp;
            tmp = tmp.next;
        }
        if(initial == 0) addAtHead(val);
        else if(index == -1 && prev != null && tmp == null) addAtTail(val);
        else if(index == -1 && prev != null && tmp != null) {
            Node tmp2 = new Node(val, null);
            prev.next = tmp2;
            tmp2.next = tmp;
        }else return;
        
    }
    
    public void deleteAtIndex(int index) {
        Node prev = new Node(-1, null);
        Node tmp = head;
        int initial = index;
        if(head == null) return;
        while(index-- > 0 && tmp != null) {
            prev = tmp;
            tmp = tmp.next;
        }
        if(initial == 0) {
            if(head == tail) head = tail = null;
            else head = head.next;
        }else if(index == -1 && tmp != null) {
            prev.next = tmp.next;
            if(prev.next == null) tail = prev;
        }else return;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */