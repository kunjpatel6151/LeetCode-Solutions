/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *temp, *prev;
    if(head==NULL) return head;
    temp=head;
    int size=0;
    while(temp!=NULL){
        temp=temp->next;
        size++;
    }
    k=k%size;
    for(int i=0;i<k;i++){
        temp=head;
        prev=head;
        temp=temp->next;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        temp->next=head;
        head=temp;
        prev->next=NULL;
    }
    return head;
}