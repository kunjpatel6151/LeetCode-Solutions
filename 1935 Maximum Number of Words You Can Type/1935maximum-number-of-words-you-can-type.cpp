class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n=text.size();
        int i=0,ans=0;
        while(i<n){
            string word;
            vector<int> h(26,0);
            while(i<n && text[i]!=' '){
                int key=text[i]-'a';
                h[key]++;
                i++;
            }
            bool flag=true;
            for(char c:brokenLetters){
                int key=c-'a';
                if(h[key]>0){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans++;
            }
            i++;
        }
        return ans;
    }
};