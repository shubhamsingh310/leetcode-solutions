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
    ListNode *mergeTwoLists(ListNode *first, ListNode *second) {
        if(first == NULL)
            return second;
        if(second == NULL) 
            return first;
        
        if(first->val < second->val) {
            first->next = mergeTwoLists(first->next, second);
            return first;
        } 
        else {
            second->next = mergeTwoLists(second->next,first);

            return second;
        }
    }
};