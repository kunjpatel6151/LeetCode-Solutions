/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *p , *q;
    p=head;
    q=head;
    if(head==NULL || head->next==NULL){
        return false;
    }
    while(q!=NULL && q->next!=NULL){
        p=p->next;
        q=q->next->next;
        if(p==q){
            return true;
        }
    }
    return false;
}