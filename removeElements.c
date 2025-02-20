/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* ptr = head;
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    while (ptr != NULL && ptr->val == val) {
        struct ListNode* temp = ptr;
        head = head->next;
        ptr = head;
        free(temp);
    }
    struct ListNode* bptr = head;
    while (ptr != NULL) {
        if (ptr->val == val) {
            bptr->next = ptr->next;
            free(ptr);
            ptr = bptr->next;
        } else {
            bptr = ptr;
            ptr = ptr->next;
        }
    }
    return head;
}
