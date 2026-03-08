class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(n==1){
            return 0;
        }
        if(n==2){
            if(s[0]>s[1]) return -1;
            else return 0;
        }
        string sorted_s=s;
        sort(sorted_s.begin(),sorted_s.end());
        if(s==sorted_s){
            return 0;
        }
        string s1=s;
        string s2=s;
        sort(s1.begin(),s1.begin()+n-1);
        sort(s2.begin()+1,s2.end());
        if(s1==sorted_s || s2==sorted_s){
            return 1;
        }
        sort(s1.begin()+1,s1.end());
        sort(s2.begin(),s2.begin()+n-1);
        if(s1==sorted_s || s2==sorted_s){
            return 2;
        }
        else{
            return 3;
        }
    }
};