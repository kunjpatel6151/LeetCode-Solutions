/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *m=NULL,*n=NULL;
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    if(list1->val<=list2->val){
        m=list1;
        list1=list1->next;
    }
    else{
        m=list2;
        list2=list2->next;
    }
    n=m;
    while(list1!=NULL && list2!=NULL){
        if(list1->val<=list2->val){
            n->next=list1;
            list1=list1->next;
        }
        else{
            n->next=list2;
            list2=list2->next;
        }
        n=n->next;
    }
    if(list1!=NULL){
        n->next=list1;
    }
    else{
        n->next=list2;
    }
    return m;
}