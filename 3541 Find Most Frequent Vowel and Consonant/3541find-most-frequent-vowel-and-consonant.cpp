class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> h(26,0);
        for(char c:s){
            int key=c-'a';
            h[key]++;
        }
        int max_v=0;
        int max_c=0;
        for(int i=0;i<26;i++){
            if(i==0 || i==4 || i==8 || i==14 || i==20){
                max_v=max(max_v,h[i]);
            }
            else{
                max_c=max(max_c,h[i]);
            }
        }
        return max_v+max_c;
    }
};