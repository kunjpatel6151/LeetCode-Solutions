class Solution {
public:
    void solve(vector<string>& ans,string s,map<char,string>& h,int i,string digits){
        if(i==digits.size()){
            ans.push_back(s);
        }
        char digit=digits[i];
        for(char c:h[digit]){
            s+=c;
            solve(ans,s,h,i+1,digits);
            s=s.substr(0,s.size()-1);
        }
        
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s;
        map<char,string> h={{'2',"abc"},
                            {'3',"def"},
                            {'4',"ghi"},
                            {'5',"jkl"},
                            {'6',"mno"},
                            {'7',"pqrs"},
                            {'8',"tuv"},
                            {'9',"wxyz"}};
        if(digits==""){
            return ans;
        }
        solve(ans,s,h,0,digits);
        return ans;
    }
};