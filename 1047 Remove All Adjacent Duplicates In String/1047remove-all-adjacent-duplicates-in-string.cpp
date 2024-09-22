class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> a;
        for(char x:s){
            if(a.empty()){
                a.push(x);
            }
            else if(x==a.top()){
                a.pop();
            }
            else{
                a.push(x);
            }
        }
        string str;
        while(!a.empty()){
            str=a.top()+str;
            a.pop();
        }
        return str;
    }
};