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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        int n=0;
        struct ListNode *temp;
        temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        temp=head;
        int N=n/2;
        for(int i=0;i<N;i++){
            s.push(temp->val);
            temp=temp->next;
        }
        if(n%2!=0){
            temp=temp->next;
        }
        while(temp!=NULL){
            if(s.top()!=temp->val){
                return false;
            }
            s.pop();
            temp=temp->next;
        }
        return s.empty();
    }
};