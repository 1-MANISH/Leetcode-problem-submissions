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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* prev=head;
        ListNode* current=head->next;
        while(current!=NULL){
            while(current!=NULL && prev->val==current->val){
                current=current->next;
            }
            if(current){
                prev->next=current;
                prev=current;
                current=current->next;
            }else{
                prev->next=NULL;
            }
        }
        return head;
    }
};