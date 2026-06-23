class MyLinkedList {
public:
    int val,size;
    MyLinkedList* next;
    MyLinkedList* tail;
    MyLinkedList(int value=-1) {
        this->val=value;
        this->size=0;
        this->next=NULL;
        this->tail=NULL;

    }
    
    int get(int index) {
        int count=0;
        MyLinkedList* current = this;
        while(current!=NULL){
            if(index==count)return current->val;
            current=current->next;
            count++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        MyLinkedList* current = this;
        this->size+=1;
        if(current->val==-1){
            // first node
            current->val=val;
            tail=current;
            return;
        }
        MyLinkedList* newNode = new MyLinkedList(current->val);
        current->val=val;
        if(current->next==NULL){// only single node
            current->next=newNode;
            tail=newNode;
        }else{// rest cases
           MyLinkedList* temp = current->next;
           current->next = newNode;
           newNode->next = temp; 
        }
    }
    
    void addAtTail(int val) {
        MyLinkedList* current = this;
        this->size+=1;
        if(current->val==-1){//first node
            current->val=val;
            tail=current;
            return;
        }
        MyLinkedList* newNode = new MyLinkedList(val);
        tail->next = newNode;
        tail=newNode;

    }
    
    void addAtIndex(int index, int val) {
        if(index>this->size)return;
        MyLinkedList* current = this;
        if(index==0){
            addAtHead(val);
            return;
        }else if(index==this->size){
            addAtTail(val);
            return;
        }else{
            this->size+=1;
            MyLinkedList* prev=NULL;
            while(index>0){
                index--;
                prev=current;
                current=current->next;
            }
            MyLinkedList* newNode = new MyLinkedList(val);
            prev->next=newNode;
            newNode->next=current;
            return;
        }

    }
    
    void deleteAtIndex(int index) {
        if(index>=this->size)return;// invalid index
        if(this->val==-1)return;// node node
        this->size-=1;
        if(this->next==NULL){
            //deleting single node
            this->val=-1;
            tail=NULL;
            return;
        }
        MyLinkedList* current = this;
        if(index==0){// two node over there
            current->val=current->next->val;
            current->next=current->next->next ?current->next->next : NULL;
            tail= current->next ? tail : current;
            return;
        }
        MyLinkedList* prev = NULL;
        int count = 0 ;
        while(current!=NULL && count< index){
            prev=current;
            current=current->next;
            count++;
        }
        
         prev->next=current ? current->next : NULL;
        if(index==this->size || index==this->size-1){
                if(index==this->size-1)tail=prev->next;
                else tail=prev;
                current->val=-1;
            }
            if(current)current->next=NULL;

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