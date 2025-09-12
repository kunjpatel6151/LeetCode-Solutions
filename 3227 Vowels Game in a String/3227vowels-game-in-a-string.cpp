class Solution {
public:
    bool doesAliceWin(string s) {
        int vowel=0;
        for(char c:s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                vowel++;
            }
        }
        if(vowel==0){
            return false;
        }
        else{
            return true;
        }
    }
};