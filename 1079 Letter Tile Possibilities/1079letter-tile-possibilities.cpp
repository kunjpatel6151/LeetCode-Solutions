class Solution {
public:
    int buildstring(vector<int>&f){
        int ways=0;
        for(int i=0;i<26;i++){
            if(f[i]>0){
                f[i]--;
                ways+=1+buildstring(f);
                f[i]++;
            }
        }
        return ways;
    }
    int numTilePossibilities(string tiles) {
        vector<int> f(26,0);
        for(char c:tiles){
            f[c-'A']++;
        }
        return buildstring(f);
    }
};