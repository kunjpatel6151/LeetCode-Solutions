class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s;
        for(int i=0;i<words.size();i++){
            int total=0;
            for(int j=0;j<words[i].size();j++){
                int key=words[i][j]-'a';
                total+=weights[key];
            }
            total%=26;
            char c='a'+(25-total);
            s+=c;
        }
        return s;
    }
};