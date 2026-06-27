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

        //1. mapping and copy to new nodes - shallow copy
        unordered_map<Node*,Node*>originalToNew;
        Node* originalCurrent=head,*copyHead=new Node(-1),*copyCurrent;
        copyCurrent=copyHead;
        while(originalCurrent!=NULL){
            copyCurrent->next = new Node(originalCurrent->val);
            copyCurrent=copyCurrent->next;
            originalToNew[originalCurrent]=copyCurrent;
            originalCurrent=originalCurrent->next;
        }

        // now making random pointer to point as per original
        originalCurrent=head;
        while(originalCurrent!=NULL){
            if(originalCurrent->random){
                Node* copyNode = originalToNew[originalCurrent];
                Node* randomCopy = originalToNew[originalCurrent->random];
                copyNode->random=randomCopy;
            }
            originalCurrent=originalCurrent->next;
        }
        return copyHead->next;
    }
};