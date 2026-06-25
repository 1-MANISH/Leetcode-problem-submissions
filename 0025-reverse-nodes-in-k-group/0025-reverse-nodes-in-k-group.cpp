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
private:
    int linkedListLength(ListNode* head){
        int len = 0 ;
        ListNode* current = head;
        while(current!=NULL){
            len++;
            current=current->next;
        }
        return len;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;
        int n = linkedListLength(head);
        if(k>n)return head;
        int rem = n ,idx = 1 , left = 1 ,right = k;
        ListNode* lastHead=head,*newHead=head,*prev=NULL,*current=head,*nxt;
        while(rem-k>=0){
            while(idx<=right){
                nxt=current->next;
                current->next=prev;
                prev=current;
                current=nxt;
                idx++;
            }
            if(lastHead==newHead){
                head=prev;
                lastHead->next=current;
                newHead=current;
            }else{
                lastHead->next=prev;
                lastHead=newHead;
                lastHead->next=current;
                newHead=current;
            }
            rem-=k;
            left = idx;
            right=left+k-1;
        }
        return head;
    }
};