class Solution {
public:
    bool check(string s){
        bool flag=true;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                continue;
            }
            else{
                flag=false;
                break;
            }
        }
        return flag;
    }
    string discountPrices(string sentence, int discount) {
        string ans="";
        int n=sentence.size();
        for(int i=0;i<n;){
            int j=i;
            while(j<n && sentence[j]!=' '){
                j++;
            }
            string s=sentence.substr(i,j-i);
            if(s.size()>1){
                if(s[0]=='$'){
                    bool flag=check(s.substr(1));
                    if(flag){
                        long long num=stoll(s.substr(1));
                        double NUM=num*(100-discount)/100.0;
                        char buf[50];
                        sprintf(buf, "%.2f", NUM);
                        ans += "$" + string(buf);
                    }
                    else{
                        ans+=s;
                    }
                }
                else{
                    ans+=s;
                }
            }
            else{
                ans+=s;
            }
            ans+=" ";
            i=j+1;
        }
        int size=ans.size();
        return ans.substr(0,size-1);
    }
};