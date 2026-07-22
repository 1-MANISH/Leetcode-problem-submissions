class Node{
public:
    int key,value;
    Node* prev,*next;
    Node(int key,int value){
        this->key=key;
        this->value=value;
        this->prev=this->next=NULL;
    }
};

class LinkedList{
public:
    unordered_map<int,Node*>mapping;
    Node* head,*tail;
    int capacity,_size;
    LinkedList(int capacity){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        this->capacity=capacity;
        this->_size = 0;
    }

    void addNode(int key , int value){
        auto it = mapping.find(key);
        if(it!=mapping.end()){
            deleteNode(key);
            addNode(key,value);
        }
        else if(_size==capacity){
            deleteNode(head->next->key);
            addNode(key,value);
        }
        else{
            Node* newNode = new Node(key,value);
            Node* prevNode = tail->prev;
            newNode->prev =prevNode;
            prevNode->next = newNode;
            tail->prev=newNode;
            newNode->next=tail;
            mapping[key]=newNode;
            _size++;
        }
    }

    void deleteNode(int key){
        auto it = mapping.find(key);
        if(it==mapping.end())return;// key not exist -  no such case
        Node* nodeToDelete = it->second;
        Node* p = nodeToDelete->prev;
        Node* n = nodeToDelete->next;
        p->next = n;
        n->prev = p;
        nodeToDelete->next=nodeToDelete->prev=NULL;
        mapping.erase(it);
        _size--;
        delete nodeToDelete;
    }

    int getNode(int key){
        auto it = mapping.find(key);
        if(it==mapping.end())return -1;// no key
        int value = it->second->value;
        deleteNode(key);
        addNode(key,value);
        return value;
    }
};

class LRUCache {
public:
    LinkedList* ll=nullptr;
    LRUCache(int capacity) {
        this->ll = new LinkedList(capacity);
    }
    
    int get(int key) {
        return ll->getNode(key);
    }
    
    void put(int key, int value) {
        ll->addNode(key,value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */