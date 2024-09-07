class Solution {
public:
    string reverseVowels(string s) {
        vector<char> str;
        int n=s.size();
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' || c=='u' || c=='U' ){
                str.push_back(c);
            }
        }
        int m=str.size();
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' || c=='u' || c=='U' ){
                s[i]=str[--m];
            }
        }
        return s;
    }
};