class Node{
public:
    int value;
    Node* next;
    Node(int value){
        this->value=value;
        this->next=NULL;
    }
};


class LinkedList {
private:
    Node* head;
    int size;
public:
    LinkedList(){
        this->head=NULL;
        this->size=0;
    }

    void addNode(int value){
        Node* newNode = new Node(value);
        newNode->next=head;
        head=newNode;
        size++;
    }

    int deleteNode(){
        if(empty())return -1;
        Node* temp = head;
        int poppedValue=temp->value;
        head=head->next;
        delete temp;
        size--;
        return poppedValue;
    }

    int topNode(){
        if(empty())return -1;
        return head->value;
    }

    bool empty(){
        return size==0;
    }

};


class MyStack {
private:
    LinkedList list;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        list.addNode(x);
    }
    
    int pop() {
        return list.deleteNode();
    }
    
    int top() {
        return list.topNode();
    }
    
    bool empty() {
        return list.empty();
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