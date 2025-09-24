class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.size();
        int l=0,r=n-1;
        int left=-1,right=-1;
        while(l<=r){
            if(s[l]!=s[r]){
                left=l;
                right=r;
                break;
            }
            l++;
            r--;
        }
        if(left==-1 && right==-1) return true;
        string s1=s.substr(0,left)+s.substr(left+1);
        string s2=s.substr(0,right)+s.substr(right+1);
        bool flag=true;
        l=0,r=s1.size()-1;
        while(l<=r){
            if(s1[l]!=s1[r]){
                flag=false;
                break;
            }
            l++;
            r--;
        }
        if(flag) return true;
        flag=true;
        l=0,r=s2.size()-1;
        while(l<=r){
            if(s2[l]!=s2[r]){
                flag=false;
                break;
            }
            l++;
            r--;
        }
        return flag;
    }
};