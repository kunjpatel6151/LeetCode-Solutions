class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        int a,b;
        for(int i=1;i<n;i++){
            a=i;
            b=n-i;
            string s1=to_string(a);
            string s2=to_string(b);
            bool flag=true;
            for(int j=0;j<s1.size();j++){
                if(s1[j]=='0'){
                    flag=false;
                    break;
                }
            }
            for(int j=0;j<s2.size();j++){
                if(s2[j]=='0'){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.push_back(a);
                ans.push_back(b);
                break;
            }
        }
        return ans;
    }
};