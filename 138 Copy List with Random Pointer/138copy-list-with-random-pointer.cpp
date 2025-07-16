/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        map<Node*,Node*> mp;
        Node* temp=head;
        Node* newhead=NULL;
        Node* prev=NULL;
        while(temp!=NULL){
            Node* newnode= new Node(temp->val);
            mp[temp]=newnode;
            if(temp==head){
                newhead=newnode;
                prev=newhead;
            }
            else{
                prev->next=newnode;
                prev=newnode;
            }
            temp=temp->next;
        }
        temp=head;
        Node* temp2=newhead;
        while(temp!=NULL && temp2!=NULL){
            temp2->random=mp[temp->random];
            temp=temp->next;
            temp2=temp2->next;
        }
        return newhead;
    }
};