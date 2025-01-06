class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> cs;
        int m=0,count=0,n=s.size();
        for(int i=0;i<n;i++){
            while(cs.find(s[i])!=cs.end()){
                cs.erase(s[count]);
                count++;
            }
            cs.insert(s[i]);
            m=max(m,i-count+1);
        }
        return m;
    }
};