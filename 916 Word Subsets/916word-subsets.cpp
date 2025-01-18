class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int N=words1.size();
        int M=words2.size();
        int maxcount[26]={0};
        for(int i=0;i<M;i++){
            int count[26]={0};
            for(char c:words2[i]){
                int C=c-'a';
                count[C]++;
            }
            for(int j=0;j<26;j++){
                maxcount[j]=max(maxcount[j],count[j]);
            }
        }
        vector<string> ans;
        for(int i=0;i<N;i++){
            int count[26]={0};
            for(char c:words1[i]){
                int C=c-'a';
                count[C]++;
            }
            bool b=true;
            for(int j=0;j<26;j++){
                if(maxcount[j]>count[j]){
                    b=false;
                    break;
                }
            }
            if(b){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
        
};
