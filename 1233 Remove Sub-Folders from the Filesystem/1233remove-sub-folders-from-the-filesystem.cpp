class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> s;
        int n=folder.size();
        for(int i=0;i<n;i++){
            s.insert(folder[i]);
        }
        vector<string> ans;
        for(int i=0;i<n;i++){
            ans.push_back(folder[i]);
            for(int j=0;j<folder[i].size();j++){
                if(folder[i][j]=='/' && s.count(folder[i].substr(0,j))){
                    ans.pop_back();
                    break;
                }
            }
        }
        return ans;

    }
};