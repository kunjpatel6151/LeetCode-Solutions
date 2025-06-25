class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index=-1;
        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                index=i;
                break;
            }
        }
        if(index==-1){
            return word;
        }
        else{
            string str="";
            int i=index;
            while(i>=0){
                str+=word[i];
                i--;
            }
            i=index+1;
            while(i<word.size()){
                str+=word[i];
                i++;
            }
            return str;
        }
    }
};