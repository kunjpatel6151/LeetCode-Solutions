class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int count=0,k=n-1;
        while(k>=0 && s[k]==' '){
            k--;
        }
        while(k>=0 && s[k]!=' '){
            k--;
            count++;
        }
        return count;
    }
};