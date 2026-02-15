class Solution {
public:
    string addBinary(string a, string b) {
        int m=a.size();
        int n=b.size();
        if(m>n){
            string zeros(m-n,'0');
            b=zeros+b;
        }
        if(n>m){
            string zeros(n-m,'0');
            a=zeros+a;
        }
        string ans;
        int carry=0;
        for(int i=a.size()-1;i>=0;i--){
            if(carry==0){
                if(a[i]=='1' && b[i]=='1'){
                    carry=1;
                    ans="0"+ans;
                }
                else if(a[i]=='1' || b[i]=='1'){
                    ans="1"+ans;
                }
                else{
                    ans="0"+ans;
                }
            }
            else{
                if(a[i]=='1' && b[i]=='1'){
                    carry=1;
                    ans="1"+ans;
                }
                else if(a[i]=='1' || b[i]=='1'){
                    carry=1;
                    ans="0"+ans;
                }
                else{
                    carry=0;
                    ans="1"+ans;
                }
            }
        }
        if(carry==1){
            ans="1"+ans;
        }
        return ans;
    }
};