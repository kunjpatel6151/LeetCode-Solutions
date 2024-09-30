class Solution {
public:
    string result(string str){
            string a;
            for(char c:str){
                if(c=='#' && a.empty()){
                    continue;
                }
                if(c=='#'){
                    a.pop_back();
                }
                else{
                    a.push_back(c);
                }
            }
            return a;
        }
    bool backspaceCompare(string s, string t) {
        string str1=result(s);
        string str2=result(t);
        return str1==str2;
    }
};