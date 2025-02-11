class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i=0;
        int n=part.size();
        while(i<s.size()){
            string str=s.substr(i,n);
            if(str==part){
                s.erase(i,n);
                i=0;
            }
            else{
                i++;
            }
        }
        return s;
    }
};