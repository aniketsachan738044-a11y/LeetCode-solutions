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
    // LC 92: Reverse Linked List II
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* a = nullptr;
        ListNode* b = nullptr;
        ListNode* c = nullptr;
        ListNode* d = nullptr;
        ListNode* temp = head;
        int n = 1;
        while (temp != nullptr) {
            if (n == left - 1) a = temp;
            if (n == left) b = temp;
            if (n == right) c = temp;
            if (n == right + 1) d = temp;
            temp = temp->next;
            n++;
        }
        c->next = nullptr;
        c = reverseList(b);
        b->next = d;
        if (a) {
            a->next = c;
            return head;
        }
        return c;
    }

    // LC 2074: Reverse Nodes in Even Length Groups
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int groupLen = 2;

        while (curr) {
            // Count how many nodes actually exist in this group
            // (may be less than groupLen if we've hit the end of the list)
            ListNode* node = curr;
            int count = 0;
            while (node && count < groupLen) {
                node = node->next;
                count++;
            }

            if (count % 2 == 0) {
                // Reverse exactly 'count' nodes starting at curr
                ListNode* prevNode = node; // node right after the group
                ListNode* cur2 = curr;
                for (int i = 0; i < count; i++) {
                    ListNode* nxt = cur2->next;
                    cur2->next = prevNode;
                    prevNode = cur2;
                    cur2 = nxt;
                }
                prev->next = prevNode;
                prev = curr;   // curr is now the tail of the reversed group
                curr = cur2;   // = node, start of next group
            } else {
                // Leave this group as-is, just advance past it
                for (int i = 0; i < count; i++) {
                    prev = curr;
                    curr = curr->next;
                }
            }
            groupLen++;
        }
        return head;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};