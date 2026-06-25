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
        ListNode* slow=head,*fast=head->next;
        while(fast!=NULL){
            int tempVal=fast->val;
            fast->val = slow->val;
            slow->val=tempVal;
            slow=fast->next;
            fast=slow?slow->next:NULL;
        }
        return head;
    }
};