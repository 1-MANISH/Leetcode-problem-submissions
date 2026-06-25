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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* prev=NULL,*slow=head,*fast=head->next;
        while(fast!=NULL){
            ListNode* nxt = fast->next;
            if(prev){
                fast->next=slow;
                slow->next=nxt;
                prev->next=fast;
                prev=slow;
            }else{
                head=fast;
                fast->next=slow;
                slow->next=nxt;
                prev=slow;
            }
            slow=nxt;
            fast=slow?slow->next:NULL;
        }
        return head;
    }
};