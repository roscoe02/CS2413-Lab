/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Dummy node to simplify edge cases
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode* previous = &dummy;  // Pointer to track previous node

    // Traverse the list
    while (previous->next) {
        if (previous->next->val == val) { // Found target value
            struct ListNode* toDelete = previous->next; // Store node to delete
            previous->next = toDelete->next; // Skip over it
            free(toDelete); // Free memory
        } else {
            previous = previous->next; // Move forward
        }
    }
    
    return dummy.next; // Return new head
}
