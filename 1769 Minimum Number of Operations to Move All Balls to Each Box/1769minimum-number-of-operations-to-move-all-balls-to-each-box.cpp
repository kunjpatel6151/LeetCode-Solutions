class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        vector<int> ans(n);
        int count=0;
        if(boxes[0]=='1'){
            count=1;
        }
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+count;
            if(boxes[i]=='1'){
                count++;
            }
        }
        count=0;
        if(boxes[n-1]=='1'){
            count=1;
        }
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]+count;
            if(boxes[i]=='1'){
                count++;
            }
        }
        for(int i=0;i<n;i++){
            ans[i]=left[i]+right[i];
        }
        return ans;
    }
};