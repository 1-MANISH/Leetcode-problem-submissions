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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)return;
        ListNode* p1,*p2,*slow=head,*fast=head->next,*current,*nxt,*t1,*t2,*prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        current=slow->next;
        while(current!=NULL){
            nxt=current->next;
            current->next=prev;
            prev=current;
            current=nxt;
        }
        slow->next=prev;
        p1=head,p2=prev;
        while(p2!=NULL){
            t1=p1->next;
            t2=p2->next;
            p1->next=p2;
            if(t1!=prev)
                p2->next=t1;
            p1=t1;
            p2=t2;
        }
        if(t1==slow)
        slow->next=NULL;
        
    }
};












































