class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        int i=0;
        int n=chars.size();
        while(i<n){
            int j=i+1;
            int count=1;
            while(j<n && chars[i]==chars[j]){
                count++;
                j++;
            }
            s+=chars[i];
            if(count>1){
                s+=to_string(count);
            }
            i=j;
        }
        chars.clear();
        for(char c:s){
            chars.push_back(c);
        }
        return s.size();
    }
};