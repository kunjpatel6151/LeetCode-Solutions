class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
            ans+=solve(i);
        }
        return ans;
    }

    int solve(int x){
        string s = to_string(x);
        int count=0;
        for(int i=1;i+1<s.size();i++){
            if((s[i]>s[i-1] && s[i]>s[i+1]) || (s[i]<s[i-1] && s[i]<s[i+1])){
                count++;
            }
        }
        return count;
    }
};