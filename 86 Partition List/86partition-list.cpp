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
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1=NULL;
        ListNode *h2=NULL;
        ListNode *b1=NULL;
        ListNode *b2=NULL;
        ListNode *h3=head;
        while(h3!=NULL){
            int value=h3->val;
            ListNode* NewNode= new ListNode(value);
            if(value<x){
                if(h1==NULL){
                    h1=NewNode;
                    b1=h1;
                }
                else{
                    b1->next=NewNode;
                    b1=b1->next;
                }
            }
            else{
                if(h2==NULL){
                    h2=NewNode;
                    b2=h2;
                }
                else{
                    b2->next=NewNode;
                    b2=b2->next;
                }
            }
            h3=h3->next;
        }
        if(h1!=NULL){
            b1->next=h2;
            return h1;
        }
        else{
            return h2;
        }
    }
};