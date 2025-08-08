class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        int n=s.size();
        string str=goal+goal;
        for(int i=0;i<n;i++){
            string temp=str.substr(i,n);
            if(temp==s){
                return true;
            }
        }
        return false;
    }
};