class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        if(m>n){
            return -1;
        }
        else{
            int i=0,j=0,k=0;
            while(i<n){
                if(haystack[k]==needle[j]){
                    j++;
                    k++;
                    if(j==m){
                        return (k-j);
                    }
                }
                else{
                    j=0;
                    i++;
                    k=i;
                }
            }
           return -1;
        }
    }
};