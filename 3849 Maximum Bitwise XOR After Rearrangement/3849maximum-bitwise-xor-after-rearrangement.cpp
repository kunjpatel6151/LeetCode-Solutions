class Solution {
public:
    string maximumXor(string s, string t) {
        int n=t.size();
        int ones=0,zeros=0;
        for(char c:t){
            if(c=='1'){
                ones++;
            }
            else{
                zeros++;
            }
        }
        
        string ans;
        for(char c:s){
            if(c=='0'){
                if(ones>0){
                    ans+="1";
                    ones--;
                }
                else{
                    ans+="0";
                    zeros--;
                }
            }
            else{
                if(zeros>0){
                    ans+="1";
                    zeros--;
                }
                else{
                    ans+="0";
                    ones--;
                }
            }
        }
        return ans;
    }
};