/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *temp, *prev;
    if(head==NULL) return head;
    temp=head;
    prev=head;
    temp=temp->next;
    while(temp!=NULL){
        if(temp->val==val){
            prev->next=temp->next;
            temp=temp->next;
        }
        else{
            prev=prev->next;
            temp=temp->next;
        }
    }
    if(head->val==val){
        head=head->next;
    }
    return head;
}