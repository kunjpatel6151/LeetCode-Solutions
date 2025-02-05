class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        int n=s1.size();
        bool flag=true;
        int h1[26]={0};
        int h2[26]={0};
        for(int i=0;i<n;i++){
            h1[s1[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            h2[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(h1[i]!=h2[i]){
                flag=false;
                break;
            }
        }
        if(!flag){
            return false;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                count++;
            }
            if(count>2){
                flag=false;
                break;
            }
        }
        return flag;

    }
};