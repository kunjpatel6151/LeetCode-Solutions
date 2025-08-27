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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k <= 1) return head;
        ListNode* temp1=head;
        ListNode* temp2=head;
        ListNode* prev=NULL;
        ListNode* newhead=NULL;
        int N=k;
        while(N--){
            prev=temp2;
            temp2=temp2->next;
        }
        newhead=prev;
        ListNode* tail=reverse(temp1,NULL,temp2);
        temp1=temp2;
        while(temp2!=NULL){
            N=k;
            while(N-- && temp2!=NULL){
                temp2=temp2->next;
            }
            if(N>=0){
                break;
            }
            tail=reverse(temp1,tail,temp2);
            temp1=temp2;
        }
        return newhead;
    }

    ListNode* reverse(ListNode* temp1,ListNode* tail,ListNode* temp2){
        ListNode* h=temp1;
        ListNode* c=h;
        ListNode* p=NULL;
        while(h!=temp2){
            h=h->next;
            c->next=p;
            p=c;
            c=h;
        }
        if(tail!=NULL){
            tail->next=p;
        }
        temp1->next=temp2;
        return temp1;
    }
};