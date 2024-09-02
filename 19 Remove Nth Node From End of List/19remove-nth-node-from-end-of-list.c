/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *temp, *prev, *todelete;
    temp = head;
    prev = head;
    int size = 0, position;
    while (temp != NULL) {
        temp = temp->next;
        size++;
    }
    temp = head;
    position = size - n;
    if (size == 1 && n==1) {
        head=NULL;
    } else {
        if (position == size) {
            while (temp->next != NULL) {
                prev = temp;
                temp = temp->next;
            }
            todelete = temp;
            prev->next = NULL;
        } else if (position == 0) {
            todelete = temp;
            head = temp->next;
        } else {
            int i = 0;
            while (i < position) {
                prev = temp;
                temp = temp->next;
                i++;
            }
            todelete = temp;
            prev->next = temp->next;
        }
    }

    return head;
}