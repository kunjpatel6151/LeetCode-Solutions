class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n=answers.size();
        unordered_map<int,int> mp;
        unordered_set<int> st;
        int ans=0;
        for(int x:answers){
            if(x==0){
                ans++;
            }
            else{
                if(!st.count(x)){
                    ans+=x+1;
                    mp[x]=x;
                    st.insert(x);
                }
                else{
                    if(mp[x]>0){
                        mp[x]--;
                    }
                    else{
                        mp[x]=x;
                        ans+=x+1;
                    }
                }
            }
        }
        return ans;
    }
};