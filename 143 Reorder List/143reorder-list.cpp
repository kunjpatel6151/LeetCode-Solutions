/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *n1=head;
        ListNode *n2=head;
        // finding middle
        while(n2!=NULL && n2->next!=NULL){
            n1=n1->next;
            n2=n2->next->next;
        }
        if(n1==head || n1->next==NULL){
            return;
        }

        ListNode *n1prev=n1; //saving right part beginning
        n1=n1->next;
        n1prev->next=NULL; // cutting off left part from right

        // reversing the right part
        n1prev=NULL;
        while(n1!=NULL){
            n2=n1;
            n1=n1->next;
            n2->next=n1prev;
            n1prev=n2;
        } 
        // Merging left and right parts
        n1=head;
        n2=n1prev;
        ListNode *n2prev=NULL;
        while(n1!=NULL && n2!=NULL){
            n1prev=n1;
            n2prev=n2;
            n1=n1->next;
            n2=n2->next;
            n1prev->next=n2prev;
            n2prev->next=n1;
        }
    }
};