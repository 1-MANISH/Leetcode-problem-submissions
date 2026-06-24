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
    const int VISITED = 1e6;
    bool hasCycle(ListNode *head) {
        
       ListNode* current = head;
       while(current!=NULL){
            if(current->val==VISITED)return true;
            current->val=VISITED;
            current=current->next;
       }
       return false;
    }
};