class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();
        map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[text[i]]++;
        }
        int count=0;
        while(mp['b']>0 && mp['a']>0 && mp['l']>1 && mp['o']>1 && mp['n']>0){
            mp['b']--;
            mp['a']--;
            mp['l']-=2;
            mp['o']-=2;
            mp['n']--;
            count++;
        }
        return count;
    }
};