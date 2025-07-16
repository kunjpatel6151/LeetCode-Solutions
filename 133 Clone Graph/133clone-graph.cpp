/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        if(node->neighbors.size()==0){
            Node* newnode= new Node(node->val);
            return newnode;
        }
        map<Node*,Node*> mp;
        Node* newnode = new Node(node->val,{});
        mp[node]=newnode;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* f=q.front();
            q.pop();
            for(Node* neighbor:f->neighbors){
                if(mp.find(neighbor)==mp.end()){
                    mp[neighbor]= new Node(neighbor->val,{});
                    q.push(neighbor);
                }
                mp[f]->neighbors.push_back(mp[neighbor]);
            }
        }
        return newnode;
    }
};