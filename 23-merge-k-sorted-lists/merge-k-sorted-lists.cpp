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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        int k=lists.size();
        struct Compare {
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;   
            }
        };

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        for(int i=0;i<k;i++){
            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
            
        }
        while(!pq.empty()){
            ListNode* t = pq.top();
            pq.pop();
            if(t->next!=NULL){
                pq.push(t->next);
            }
            if(head==NULL){
                head=t;
                tail=t;
            }
            else{
                tail->next=t;
                tail=t;
                tail->next=NULL;
            }            
        }
        return head;
    }
};