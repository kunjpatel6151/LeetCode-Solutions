class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            s=word(s);
        }
        return s[k-1];
    }

    string word(string s){
        string str="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='z'){
                str+='a';
            }
            else{
                str+=(s[i]+1);
            }
        }
        return s+str;
    }
};