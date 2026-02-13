class Solution {
public:
    int f(char x,char y,char z,string s){
        int n=s.size();
        int ans=0;
        int i=0;
        while(i<n){
            if(s[i]==z){
                i++;
                continue;
            }
            unordered_map<int,int> mp;
            int val=0;
            mp[val]=i;
            int j=i;
            while(j<n && s[j]!=z){
                if(s[j]==x) val++;
                else val--;
                if(mp.find(val)!=mp.end()){
                    ans=max(ans,j-mp[val]+1);
                }
                else{
                    mp[val]=j+1;
                }
                j++;
            }
            i=j;
        }
        return ans;
    }
    int longestBalanced(string s) {
        int n=s.size();
        int ans=1;
        int count=0;
        for(int i=1;i<n;i++){
            if(s[i-1]==s[i]){
                count++;
                ans=max(ans,count+1);
            }
            else{
                count=0;
            }
        }
        ans=max(ans,f('a','b','c',s));
        ans=max(ans,f('a','c','b',s));
        ans=max(ans,f('b','c','a',s));
        
        map<pair<int,int>,int> mp;
        int ca=0, cb=0, cc=0;
        mp[{0,0}]=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='a') ca++;
            else if(s[i]=='b') cb++;
            else cc++;
            if(mp.find({ca-cb,cb-cc})!=mp.end()){
                ans=max(ans,i-mp[{ca-cb,cb-cc}]);
            }
            else{
                mp[{ca-cb,cb-cc}]=i;
            }
        }
        return ans;
    }
};