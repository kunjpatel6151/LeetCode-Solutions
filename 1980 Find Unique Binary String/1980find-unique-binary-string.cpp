class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        int total= 1 << n;
        vector<string> s;
        for(int i=0;i<total;i++){
            string str="";
            for(int j=n-1;j>=0;j--){
                str+=(i & (1 << j)) ? '1' : '0';
            }
            s.push_back(str);
        }
        string ans;
        for(int i=0;i<total;i++){
            string s1=s[i];
            bool flag=false;
            for(int j=0;j<n;j++){
                string s2=nums[j];
                if(s1==s2){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                ans=s1;
                break;
            }
        }
        return ans;
    }
};