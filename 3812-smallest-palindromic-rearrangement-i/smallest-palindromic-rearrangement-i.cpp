class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> v(26,0);
        for(char c:s){
            int k=c-'a';
            v[k]++;
        }
        int n=s.size();
        string ans(n,' ');
        int left=0,right=n-1;
        for(int i=0;i<26;i++){
            while(v[i]>=2){
                ans[left]=char('a' + i);
                ans[right]=char('a' + i);
                left++;
                right--;
                v[i]-=2;
            }
            if(v[i]==1){
                ans[n/2]=char('a'+i);
                v[i]=0;
            }
        }
        return ans;

        
    }
};