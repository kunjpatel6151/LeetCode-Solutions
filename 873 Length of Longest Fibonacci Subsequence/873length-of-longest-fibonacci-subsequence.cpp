class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(arr[i]);
        }
        int ans=2;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x=arr[i];
                int y=arr[j];
                int count=2;
                while(s.count(x+y)){
                    count++;
                    int z=x+y;
                    x=y;
                    y=z;
                }
                ans=max(count,ans);
            }
        }
        return (ans>2)? ans:0;
    }
};