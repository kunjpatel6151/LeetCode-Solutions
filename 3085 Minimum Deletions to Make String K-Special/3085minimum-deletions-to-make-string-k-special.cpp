class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n=word.size();
        vector<int> h(26,0);
        for(int i=0;i<n;i++){
            int c=word[i]-'a';
            h[c]++;
        }
        vector<int> freq;
        for(int i=0;i<26;i++){
            if(h[i]>0){
                freq.push_back(h[i]);
            }
        }
        sort(freq.begin(),freq.end());
        int ans=INT_MAX;
        int m=freq.size();
        for(int i=0;i<m;i++){
            int base=freq[i];
            int count=0;
            for(int j=0;j<m;j++){
                if(freq[j]<base){
                    count+=freq[j];
                }
                else if(freq[j]>base+k){
                    count+=freq[j]-(base + k);
                }
            }
            ans=min(count,ans);
        }
        return ans;
        
        
    }
};