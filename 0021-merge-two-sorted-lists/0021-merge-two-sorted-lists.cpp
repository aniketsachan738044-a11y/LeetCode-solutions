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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* c = new ListNode(100);
        ListNode* temp = c;
        
        while(a != nullptr && b != nullptr) {
            if(a->val <= b->val) {
                temp->next = a;   // 🛠️ FIX: Linked the node from 'a' before moving
                a = a->next;
                temp = temp->next;
            } else {
                temp->next = b;
                b = b->next;
                temp = temp->next;
            }
        }
        
        if(a == nullptr) 
            temp->next = b;
        else 
            temp->next = a;
            
        return c->next;
    }
};
