class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int pos=-1;
        for(int i=n-1;i>=0;i--){
            if(num[i]=='1' || num[i]=='3' || num[i]=='5' || num[i]=='7' || num[i]=='9'){
                pos=i;
                break;
            }
        }
        string s;
        if(pos==-1){
            return s;
        }
        s=num.substr(0,pos+1);
        return s;
    }
};