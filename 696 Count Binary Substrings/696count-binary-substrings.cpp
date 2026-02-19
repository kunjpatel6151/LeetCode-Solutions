class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        int ans=0;
        int i=0;
        int curr=0,prev=0;
        bool flag=true;
        while(i<n){
            int j=i;
            curr=0;
            if(flag){
                while(j<n && s[j]=='0'){
                    j++;
                    curr++;
                }
            }
            else{
                while(j<n && s[j]=='1'){
                    j++;
                    curr++;
                }
            }
            flag=!flag;
            ans+=min(curr,prev);
            prev=curr;
            i=j;
        }

        return ans;
    }
};