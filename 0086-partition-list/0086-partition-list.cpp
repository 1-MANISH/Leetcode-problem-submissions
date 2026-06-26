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
        ListNode* ptr1 = new ListNode(-1),*ptr2 = new ListNode(-1),*current=head;
        ListNode* ansHead =ptr1,*ptr2Head=ptr2;
        while(current!=NULL){
            if(current->val<x){
                ptr1->next=new ListNode(current->val);
                ptr1=ptr1->next;
            }else{
                ptr2->next=new ListNode(current->val);
                ptr2=ptr2->next;
            }
            current=current->next;
        }
        ptr1->next=ptr2Head->next;
        return ansHead->next;
    }
};