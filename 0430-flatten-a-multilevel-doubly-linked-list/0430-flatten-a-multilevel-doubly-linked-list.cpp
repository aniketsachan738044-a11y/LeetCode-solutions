/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;

            if (temp->child != NULL) {
                Node* child = temp->child;
                temp->child = NULL;
                temp->next = child;
                child->prev = temp;

                Node* tail = child;
                while (tail->next != NULL) {
                    tail = tail->next;
                }

                tail->next = next;
                if (next != NULL) {
                    next->prev = tail;
                }
            }

            temp = temp->next;   // <-- was: temp = next;
        }
        return head;
    }
};