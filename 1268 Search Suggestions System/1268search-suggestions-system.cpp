class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> ans;
        string pre="";
        for(char c:searchWord){
            pre+=c;
            vector<string> s;
            for(const string &pr:products){
                if(pr.find(pre)==0){
                    s.push_back(pr);
                    if(s.size()==3){
                        break;
                    }
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};