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
    int getDecimalValue(ListNode* head) {
        string str="";
        ListNode* temp=head;
        while(temp!=NULL){
            string s=to_string(temp->val);
            str+=s;
            temp=temp->next;
        }
        long long ans=0;
        for(char c:str){
            int digit=c-'0';
            ans=2*ans+digit;
        }
        return (int)ans;

    }
};