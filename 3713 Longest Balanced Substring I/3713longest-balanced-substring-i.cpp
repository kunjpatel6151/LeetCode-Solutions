class Solution {
public:
    bool check(vector<int>& h){
        int val=0;
        for(int i=0;i<26;i++){
            if(h[i]==0){
                continue;
            }
            if(h[i]!=0 && val==0){
                val=h[i];
            }
            if(h[i]!=0 && val!=0){
                if(h[i]!=val){
                    return false;
                }
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> h(26,0);
            for(int j=i;j<n;j++){
                int key=s[j]-'a';
                h[key]++;
                if(check(h)){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};