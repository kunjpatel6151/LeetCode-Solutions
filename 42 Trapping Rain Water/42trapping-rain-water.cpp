class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0]=height[0];
        suffix[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=max(height[i],prefix[i-1]);
            suffix[n-1-i]=max(height[n-1-i],suffix[n-i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int leftheight=prefix[i];
            int rightheight=suffix[i];
            if(leftheight>height[i] && rightheight>height[i]){
                ans+=min(leftheight,rightheight)-height[i];
            }
        }
        return ans;
    }
};