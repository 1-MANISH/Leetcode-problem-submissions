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

template <typename T>
using MinHeap = priority_queue<T,vector<T>,greater<T>>;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy,*head;
        head = dummy = new ListNode(-1);
        MinHeap<pair<int,ListNode*>>mn_heap;
        for(auto &list:lists){
            if(list!=NULL)mn_heap.push({list->val,list});
        }
        while(!mn_heap.empty()){
            auto[value,node] = mn_heap.top();
            mn_heap.pop();
            dummy->next=new ListNode(value);
            dummy = dummy->next;
            if(node->next!=NULL){
                mn_heap.push({node->next->val,node->next});
            }
        }
        return head->next;
    }
};