class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int d=abs(arr[0]-arr[1]);
        for(int i=2;i<n;i++){
            d=min(abs(arr[i-1]-arr[i]),d);
        }
        vector<vector<int>> ans;
        for(int i=1;i<n;i++){
            if(d==abs(arr[i-1]-arr[i])){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};