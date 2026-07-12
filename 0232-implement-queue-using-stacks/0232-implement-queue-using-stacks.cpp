class Node{
    public:
    int value;
    Node* next;

    Node(int value){
        this->value=value;
        this->next=NULL;
    }
};

class LinkedList{
    public:
    Node* head,*tail;
    int _size;

    LinkedList(){
        this->_size=0;
    }

    void insertAtTail(int x){
        Node* newNode = new Node(x);
        if(size()==0){
            tail=head=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
        _size++;
    }
    int deleteAtHead(){
        if(size()==0)return -1;
        Node* temp = head;
        head=head->next;
        int value = temp->value;
        delete temp;
        _size--;
        return value;
    }
    int size(){
        return _size;
    }
};


class MyQueue {
    LinkedList ll;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        ll.insertAtTail(x);
    }
    
    int pop() {
        return ll.deleteAtHead();
    }
    
    int peek() {
        return ll.size()==0?-1:ll.head->value;
    }
    
    bool empty() {
        return ll.size()==0;
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