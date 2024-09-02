class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string str;
        int i=0;
        while(i<n){
            char c=s[i];
            if(c>='a' && c<='z'){
                str.push_back(c);
            }
            else if(c>='A' && c<='Z'){
                c=tolower(c);
                str.push_back(c);
            }
            else if(c>='0' && c<='9'){
                str.push_back(c);
            }
            i++;
        }
        string str1=str;
        reverse(str.begin(),str.end());
        if(str1==str){
            return true;
        }
        else{
            return false;
        }

    }
};