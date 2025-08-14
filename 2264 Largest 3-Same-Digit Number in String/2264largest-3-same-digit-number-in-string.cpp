class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        int i=0;
        /*
        if(num[0]=='0'){
            i++;
            if(num[1]=='0'){
                i++;
                if(num[2]=='0'){
                    i++;
                }
            }
        }
        */
        string ans;
        while(i<n){
            string str=num.substr(i,3);
            char c1=str[0];
            char c2=str[1];
            char c3=str[2];
            if(c1==c2 && c2==c3){
                if(ans==""){
                    ans=str;
                }
                else{
                    if(stoi(str)>stoi(ans)){
                        ans=str;
                    }
                }
            }
            i++;
        }
        return ans;
    }
};