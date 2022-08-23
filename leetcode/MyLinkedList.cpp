class MyLinkedList {
public:
    
    class Node {
    public:
        int val;
        Node* next;
        Node(int val, Node* next = nullptr): val(val), next(next) {}
    };
    
    Node* head = nullptr;
    Node* tail = nullptr;
    
    MyLinkedList() {
        
    }
    
    int get(int index) {
        Node* tmp = head;
        while(index-- && tmp) tmp = tmp->next;
        if(!tmp)  return -1;
        return tmp->val;
    }
    
    void addAtHead(int val) {
        Node* tmp = new Node(val);
        if(!head) {
            head = tail = tmp;
            return;
        }
        tmp->next = head;
        head = tmp;
    }
    
    void addAtTail(int val) {
        Node* tmp = new Node(val);
        if(!head) {
            head = tail = tmp;
            return;
        }
        tail->next = tmp;
        tail = tmp;
    }
    
    void addAtIndex(int index, int val) {
        Node* prev = new Node(-1);
        Node* tmp = head;
        int initial = index;
        while(index-- && tmp) {
            prev = tmp;
            tmp = tmp->next;
        }
        if(initial == 0) {
            addAtHead(val);
        }else if(prev && !tmp && index == -1){
            addAtTail(val);
        }else if(prev && tmp) {
            Node* newTmp = new Node(val);
            prev->next = newTmp;
            newTmp->next = tmp;
        }else return;
    }
    
    void deleteAtIndex(int index) {
        Node* prev = new Node(-1);
        Node* tmp = head;
        int initial = index;
        if(!head) return;
        while(index-- && tmp) {
            prev = tmp;
            tmp = tmp->next;
        }
        if(initial == 0) {
            Node* tmp2 = head;
            if(head == tail) head = tail = nullptr;
            else head = head->next;
            delete tmp2;
        }else if(index == -1 && tmp) {
            Node* tmp2 = tmp;
            prev->next = tmp->next;
            if(!prev->next) tail = prev;
            delete tmp2;
        }else return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */