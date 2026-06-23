class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

class MyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    MyLinkedList() {
        this->head=NULL;
        this->tail=NULL;
        this->size=0;
    }
    
    int get(int index) {
        if(index>=size && index<0)return -1;
        Node* current = head;
        int cnt = 0 ;
        while(cnt<index ){
            current=current->next;
            cnt++;
        }
        return current? current->val:-1;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        if(head==NULL)tail=newNode;
        head=newNode;
        size++;
    }
    
    void addAtTail(int val) {
        if(head==NULL ){
            addAtHead(val);
            return;
        }
        tail->next=new Node(val);
        tail=tail->next;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size)return;
       
        if(index==0){
            addAtHead(val);
            return;
        }
        if(index==size){
            addAtTail(val);
            return;
        }
        size++;
        int cnt = 0;
        Node* current = head;
        while(cnt<index-1){
            current=current->next;
            cnt++;
        }
        Node* newNode = new Node(val);
        Node* temp = current->next;
        current->next=newNode;
        newNode->next = temp;
    }
    
    void deleteAtIndex(int index) {
        if(head==NULL)return;
        if(index<0)return;
        if(index>=size)return;
        if(index==size-1){
            Node* current = head;
            Node* prev;
            while(current!=NULL && current->next!=NULL){
                prev=current;
                current=current->next;
            }
            if(prev){
                prev->next=NULL;
                tail=prev;
            }else head=prev=NULL;
            delete current;
            size--;
            return;
        }
        size--;
        if(index==0){
            Node* temp = head;
            head=head->next;
            delete temp;
            return;
        }
        Node* current = head;
        int cnt = 0;
        while(cnt<index-1){
            current=current->next;
            cnt++;
        }
        Node* temp = current->next;
        current->next = temp?temp->next:NULL;
        delete temp;
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