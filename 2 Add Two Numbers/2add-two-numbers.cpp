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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* newhead=NULL;
        ListNode* temp=newhead;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL || carry!=0){
            int x=temp1 ? temp1->val:0;
            int y=temp2 ? temp2->val:0;
            int result=x+y+carry;
            carry=result/10;
            result=result%10;
            ListNode* newNode= new ListNode(result);
            if(newhead==NULL){
                newhead=newNode;
                temp=newhead;
            }
            else{
                temp->next=newNode;
                temp=newNode;
            }
            temp1=temp1 ? temp1->next:NULL;
            temp2=temp2 ? temp2->next:NULL;
        }
        return newhead;
    }
};