/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||head->next==NULL)return head;

        if(left>=right)return head;

        ListNode* current = head,
        *prev=NULL, 
        *nxt=NULL,*newHead ,*lastHead=head;

        int idx = 1;
        while(idx<left && current!=NULL){
            lastHead=current;
            current=current->next;
            idx++;
        }
        idx=left;
        newHead=current;
        prev=NULL;
        while(current!=NULL && idx<=right){
            nxt=current->next;
            current->next=prev;
            prev=current;
            current=nxt;
            idx++;
        }

        if(lastHead!=newHead){
            lastHead->next=prev;
            newHead->next=current;
            return head;
        }else{
            newHead->next=current;
            return prev;
        }
    }
};