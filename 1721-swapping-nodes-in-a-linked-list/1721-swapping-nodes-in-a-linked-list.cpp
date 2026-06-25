/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    private:
    int ListLength(ListNode* head){
        ListNode* current = head;
        int len = 0;
        while(current!=NULL)len++,current=current->next;
        return len;
    }
    public:
        ListNode* swapNodes(ListNode *head, int k) {
            if(head==NULL || head->next==NULL)return head;
            int n = ListLength(head);
            int begin = k , end = n-k+1 ,idx = 1;
            ListNode* current=head,*ptr1,*ptr2;
            while(current!=NULL){
                if(idx==begin){
                    ptr1=current;
                }
                if(idx==end){
                    ptr2=current;
                }
                idx++;
                current=current->next;
            }
            int temp = ptr2->val;
            ptr2->val=ptr1->val;
            ptr1->val=temp;
            return head;
        }
};