class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        vector<string> ans;
        int i=0;
        while(i<n){
            if(n-i<k){
                string str=s.substr(i);
                while(str.size()!=k){
                    str+=fill;
                }
                ans.push_back(str);
            }
            else{
                string str=s.substr(i,k);
                ans.push_back(str);
            }
            i+=k;
        }
        return ans;
    }
};