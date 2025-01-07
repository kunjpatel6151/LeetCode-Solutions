class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        set<string> s;
        int n=words.size();
        for(int i=0;i<n;i++){
            int M=words[i].size();
            for(int j=0;j<n;j++){
                int m=words[j].size();
                if(i!=j && M<=m){
                    bool b=false;
                    for(int k=0;k<m;k++){
                        string str=words[j].substr(k,M);
                        if(str==words[i]){
                            s.insert(str);
                        }
                    }
                }
            }
        }
        for(string str:s){
            ans.push_back(str);
        }
        return ans;
    }
};