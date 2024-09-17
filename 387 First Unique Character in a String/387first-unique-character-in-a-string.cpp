class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size(),index;
        int a[26]={0};
        for(int i=0;i<n;i++){
            int j=s[i]-'a';
            a[j]=a[j]+1;
        }
        bool b=true;
        for(int i=0;i<n;i++){
            int j=s[i]-'a';
            if(a[j]==1){
                index=i;
                b=false;
                break;
            }
        }
        if(b){
            return -1;
        }
        else{
            return index;
        }
    }
};