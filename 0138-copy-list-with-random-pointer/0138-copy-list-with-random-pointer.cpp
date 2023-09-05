/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)return NULL;
        for(Node *curr = head; curr != NULL; curr = curr->next){
            Node *newNode = new Node(curr->val);
            Node *next = curr->next;
            curr->next = newNode;
            curr = newNode;
            newNode->next = next;
        }
        for(Node *curr = head; curr != NULL; curr = curr->next->next){
            Node *copy = curr->next;
            copy->random = (curr->random == NULL) ?  NULL : curr->random->next;
        }
        Node *dummyHead = new Node(0), *currCopyPtr = dummyHead;
        for(Node *curr = head; curr != NULL; curr = curr->next){
              currCopyPtr->next = curr->next;
              currCopyPtr = curr->next;
              curr->next = currCopyPtr->next;
        }
        return dummyHead->next;
    }
};