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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int>m;
        ListNode* current = head;
        while(current!=NULL){
            if(m[current])return true;
            m[current]++;
            current=current->next;
        }
        return false;
       
    }
};