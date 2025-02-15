class Solution {
public:
    bool partition(string s, int target){
        if(s=="" && target==0) return true;
        if(target<0) return false;
        bool ans=false;
        for(int i=0;i<s.size();i++){
            string left=s.substr(0,i+1);
            string right=s.substr(i+1);
            int leftnum=stoi(left);
            bool flag=partition(right,target-leftnum);
            if(flag){
                ans=true;
                return ans;
            }
        }
        return ans;
    }
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            string str=to_string(i*i);
            if(partition(str,i)){
                sum+=i*i;
            }
        }
        return sum;
    }
    
};