class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size(), m=word2.size(),j=0,k=0,i=0;
        string word;

        while(i<(n+m)){
            if(i%2==0){
                if(i<2*n){
                    word+=word1[j];
                    j++;
                }
                else{
                    word+=word2[k];
                    k++;
                }
            }
            else{
                if(i<2*m){
                    word+=word2[k];
                    k++;
                }
                else{
                    word+=word1[j];
                    j++;
                }
            }
            i++;
        }
        return word;
    }
};