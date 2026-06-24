/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)return NULL;
        if(head==head->next)return head;
        ListNode* slow = head ,*fast = head->next , *prev=NULL;
        bool isCycle = false;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                isCycle=true;
                break;
            }
        }
        if(!isCycle)return NULL;
        slow=head;
        while(prev!=fast){
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        return prev;
    }
};