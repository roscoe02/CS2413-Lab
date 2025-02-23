/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Dummy node
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode* prev = &dummy;  // Pointer to track previous node

    // Traverse the list
    while (prev->next) {
        if (prev->next->val == val) { // Found target value
            struct ListNode* toDelete = prev->next; // Store node to delete
            prev->next = toDelete->next; // Skip over it
            free(toDelete); // Free memory
        } else {
            prev = prev->next; // Move forward
        }
    }
    
    return dummy.next; // Return new head
}
