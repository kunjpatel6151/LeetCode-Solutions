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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* slow_prev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow_prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        slow_prev->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(slow);
        return merge(left,right);
    }

    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(h1!=NULL && h2!=NULL){
            if(h1->val<=h2->val){
                if(head==NULL){
                    head=h1;
                    tail=h1;
                }
                else{
                    tail->next=h1;
                    tail=tail->next;
                }
                h1=h1->next;
            }
            else{
                if(head==NULL){
                    head=h2;
                    tail=h2;
                }
                else{
                    tail->next=h2;
                    tail=tail->next;
                }
                h2=h2->next;
            }
        }
        while(h1!=NULL){
            if(head==NULL){
                head=h1;
                tail=h1;
            }
            else{
                tail->next=h1;
                tail=tail->next;
            }
            h1=h1->next;
        }
        while(h2!=NULL){
            if(head==NULL){
                head=h2;
                tail=h2;
            }
            else{
                tail->next=h2;
                tail=tail->next;
            }
            h2=h2->next;
        }
        return head;
    }
};