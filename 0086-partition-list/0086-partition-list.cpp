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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p1H = new ListNode(-1) , *p2H = new ListNode(-1) ,*p1,*p2,*current=head;
        p1=p1H,p2=p2H;

        while(current!=NULL){
            if(current->val<x){
                p1->next=current;
                p1=p1->next;
            }else{
                p2->next=current;
                p2=p2->next;
            }
            current=current->next;
        }
        p1->next=p2H->next;
        p2->next=NULL;
        return p1H->next;

    }
};