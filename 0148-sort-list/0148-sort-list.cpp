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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        ListNode* p1 =list1->val<=list2->val? list1:list2,*p2,*prev=NULL;
        p2=p1==list1?list2:list1;
        ListNode* mainHead=p1;
        while(p1!=NULL && p2!=NULL){
            if(p1->val<=p2->val){
                prev=p1;
                p1=p1->next;
            }else {
                prev->next=p2;
                prev=p2;
                p2=p2->next;
                p2=p1;
                p1=prev->next;
            }
        }
        if(p1==NULL)prev->next=p2;
        else if(p2==NULL)prev->next=p1;
        return mainHead;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        //findmid
        ListNode* slow=head,*fast=head->next->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* l1,*l2;
        l2=slow->next;
        slow->next=NULL;
        l1 =head;
        //sort further
        ListNode* sort1Result = sortList(l1);
        ListNode* sort2Result = sortList(l2);
        //now merge
        ListNode* mergeResult = mergeTwoLists(sort1Result,sort2Result);
        return mergeResult;
    }
};