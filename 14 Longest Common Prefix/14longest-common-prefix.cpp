class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        int n=strs.size();
        int m=strs[0].size();
        for(string str:strs){
            int M=str.size();
            m=min(m,M);
        }
        for(int i=0;i<m;i++){
            char c=strs[0][i];
            bool b=true;
            for(int j=0;j<n;j++){
                if(c!=strs[j][i]){
                    b=false;
                }
            }
            if(b){
                s+=c;
            }
            else{
                break;
            }
        }
        return s;
    }
};