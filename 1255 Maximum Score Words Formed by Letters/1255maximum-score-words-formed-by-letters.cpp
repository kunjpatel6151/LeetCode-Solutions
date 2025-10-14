class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> h(26,0);
        for(char c:letters){
            h[c-'a']++;
        }
        int ans=0;
        solve(0,words,h,score,0,ans);
        return ans;
    }

    void solve(int i, vector<string>& words, vector<int>& h, vector<int>& score, int curr, int &ans){
        if(i==words.size()){
            ans=max(ans,curr);
            return;
        }
        solve(i+1,words,h,score,curr,ans);
        vector<int> temp=h;
        bool flag=true;
        int wordscore=0;
        for(char c:words[i]){
            if(temp[c-'a']<=0){
                flag=false;
                break;
            }
            temp[c-'a']--;
            wordscore+=score[c-'a'];
        }
        if(flag){
            solve(i+1,words,temp,score,curr+wordscore,ans);
        }
    }
};