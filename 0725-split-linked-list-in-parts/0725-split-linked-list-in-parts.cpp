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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            n++;
        }

        vector<ListNode*> ans;
        int size = n / k;
        int rem = n % k;
        temp = head;

        while (temp != NULL) {
            ListNode* dummy = new ListNode(0);
            ListNode* tail = dummy;
            int s = size;
            if (rem > 0) s++;
            rem--;

            for (int i = 1; i <= s; i++) {
                tail->next = temp;
                temp = temp->next;
                tail = tail->next;
            }
            tail->next = NULL;
            ans.push_back(dummy->next);
        }

        if ((int)ans.size() < k) {
            int extra = k - (int)ans.size();
            for (int i = 1; i <= extra; i++) {
                ans.push_back(NULL);
            }
        }

        return ans;
    }
};