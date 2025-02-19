class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> s[11];
        s[1]={"a","b","c"};
        for(int i=2;i<=n;i++){
           for(const string &str:s[i-1]){
            for(char c:{'a','b','c'}){
                if(str.back()!=c){
                    s[i].push_back(str+c);
                }
            }
           }
        }
        int size=s[n].size();
        if(size<k){
            return "";
        }
        return s[n][k-1];        
    }
};