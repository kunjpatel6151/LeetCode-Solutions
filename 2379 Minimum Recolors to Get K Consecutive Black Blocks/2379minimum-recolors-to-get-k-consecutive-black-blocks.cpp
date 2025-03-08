class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int m=k;
        int l=0,r=0;
        int count=0;
        while(r<k){
            if(blocks[r]=='W') count++;
            r++;
        }
        m=min(m,count);
        while(r<n){
            if(blocks[r]=='W') count++;
            if(blocks[l]=='W') count--;
            l++;
            r++;
            m=min(m,count);
        }
        return m;
    }
};