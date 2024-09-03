/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *temp, *prev;
    if(head==NULL) return head;
    temp=head;
    prev=head;
    temp=temp->next;
    int a;
    if(head==NULL) return head;
    while(temp!=NULL){
       if(temp->val==prev->val){
        temp=temp->next;
       }
       else{
        prev->next=temp;
        temp=temp->next;
        prev=prev->next;
       }
    }
    prev->next=NULL;
    return head;
}