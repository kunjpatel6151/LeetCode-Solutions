class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> h(26,0);
            for(int j=i;j<n;j++){
                int key=s[j]-'a';
                h[key]++;
                if(check(h)){
                    int m=INT_MAX,M=INT_MIN;
                    for(int i=0;i<26;i++){
                        if(h[i]==0){
                            continue;
                        }
                        m=min(m,h[i]);
                        M=max(M,h[i]);
                    }
                    ans+=M-m;
                }
            }
        }
        return ans;
    }

    bool check(vector<int>& h){
        int count=0;
        for(int freq:h){
            if(freq>0){
                count++;
            }
        }
        return count>=2;
    }
};