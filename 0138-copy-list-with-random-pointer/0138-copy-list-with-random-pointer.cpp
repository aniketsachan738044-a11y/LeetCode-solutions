class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // step 1 -> create the deep copy without random pointer
        Node* dummy = new Node(0);
        Node* tempC = dummy;
        Node* temp = head;
        while (temp) {
            Node* a = new Node(temp->val);
            tempC->next = a;
            tempC = tempC->next;
            temp = temp->next;
        }
        Node* duplicate = dummy->next;

        // step 2 -> interleave original and duplicate nodes
        Node* a = head;
        Node* b = duplicate;
        dummy = new Node(-1);
        Node* tempD = dummy;
        while (a) {
            tempD->next = a;
            a = a->next;
            tempD = tempD->next;

            tempD->next = b;
            b = b->next;
            tempD = tempD->next;
        }
        dummy = dummy->next; // head of interleaved list

        // step 3 -> assigning random pointers
        Node* t1 = dummy;
        while (t1) {
            Node* t2 = t1->next;              // duplicate of t1
            if (t1->random) t2->random = t1->random->next;
            t1 = t1->next->next;              // next original node
        }

        // step 4 -> separating original and duplicate lists
        Node* d1 = new Node(-1);
        Node* d2 = new Node(-1);
        t1 = d1;
        Node* t2 = d2;
        Node* t = dummy;
        while (t) {
            t1->next = t;
            t = t->next;
            t1 = t1->next;

            t2->next = t;
            t = t->next;
            t2 = t2->next;
        }
        t1->next = NULL;
        t2->next = NULL;

        return d2->next;
    }
};