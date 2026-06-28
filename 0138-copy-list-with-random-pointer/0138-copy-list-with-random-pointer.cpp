/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return head;
        
        // 3 pass solution - without hashing/mapping

        //1.creating in house mapping - by linking
        Node* originalCurrent=head;
        while(originalCurrent!=NULL){
            Node* originalNext = originalCurrent->next;
            originalCurrent->next = new Node(originalCurrent->val);
            originalCurrent->next->next=originalNext;
            originalCurrent=originalNext;
        }

        //2.now linking random pointer to point as per original
        originalCurrent=head;
        while(originalCurrent!=NULL){
            if(originalCurrent->random){
               originalCurrent->next->random = originalCurrent->random->next;
            }
            originalCurrent=originalCurrent->next->next;
        }

        //3. now linking next pointer
        originalCurrent=head;
        Node* copyHead=originalCurrent->next;
        while(originalCurrent!=NULL){
            Node* copyCurrent = originalCurrent->next;
            originalCurrent->next=copyCurrent->next; 
            copyCurrent->next=originalCurrent->next?originalCurrent->next->next:NULL;
            originalCurrent=originalCurrent->next;
            copyCurrent=copyCurrent->next;
        }

        return copyHead;
    }
};