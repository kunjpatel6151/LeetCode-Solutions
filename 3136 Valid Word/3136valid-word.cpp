class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3){
            return false;
        }
        int vowel=0;
        int consonant=0;
        for(char c:word){
            if(c>='0' && c<='9'){
                continue;
            }
            else if(c>='a' && c<='z'){
                if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                    vowel++;
                }
                else{
                    consonant++;
                }
            }
            else if(c>='A' && c<='Z'){
                if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                    vowel++;
                }
                else{
                    consonant++;
                }
            }
            else{
                return false;
            } 
        }
        if(vowel>0 && consonant>0){
            return true;
        }
        else{
            return false;
        }
    }
};