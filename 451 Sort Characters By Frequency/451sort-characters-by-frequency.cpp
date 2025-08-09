class Solution {
public:
    string frequencySort(string s) {
        vector<int> h(62,0);
        int n=s.size();
        for(int c:s){
            if(c>='A' && c<='Z'){
                h[c-'A']++;
            }
            else if(c>='a' && c<='z'){
                h[26+c-'a']++;
            }
            else{
                h[52+c-'0']++;
            }
        }
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<62;i++){
            if(h[i]>0){
                char c;
                if(i<26){
                    c='A'+i;
                }
                else if(i<52){
                    c='a'+i-26;
                }
                else{
                    c='0'+i-52;
                }
                pq.push({h[i],c});
            }
        }
        string ans;
        while(!pq.empty()){
            char key=pq.top().second;
            int val=pq.top().first;
            pq.pop();
            ans+=string(val,key);
        }
        return ans;
    }
};