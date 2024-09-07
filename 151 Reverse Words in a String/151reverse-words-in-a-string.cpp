class Solution {
public:
    string reverseWords(string s) {
       vector<string> str;
       int n=s.size();
       int i=n-1,j=n-1;
       while(i>=0){
        string S;
        int k=0;
        while(j>=0){
            if(s[j]==' '){
                j--;
                break;
            }
            S.push_back(s[j]);
            k++;
            j--;
        }
        if(k>0){
            reverse(S.begin(),S.end());
            str.push_back(S);
        }
        i=j;        
       }
       string result;
       int m=str.size();
       for(int k=0;k<m;k++){
        if(k!=m-1){
            result+=str[k];
            result+=" ";
        }
        else{
            result+=str[k];
        }
       }
       return result;
    }
};