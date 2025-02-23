/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (!head || !head->next) return head; // Return if empty or single node

    struct ListNode* previous = NULL;
    struct ListNode* current = head;
    
    while (current) {
        struct ListNode* nextNode = current->next; // Store next node
        current->next = previous; // Reverse link
        previous = current; // Move previous forward
        current = nextNode; // Move current forward
    }
    
    return previous; // New head of reversed list
}
