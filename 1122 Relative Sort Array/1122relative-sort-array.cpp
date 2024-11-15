class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        vector<int> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr2[i]==arr1[j]){
                    ans.push_back(arr2[i]);
                    arr1[j]=-1;
                }
            }
        }
        vector<int> a;
        for(int i=0;i<n;i++){
            if(arr1[i]!=-1){
                a.push_back(arr1[i]);
            }
        }
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
            ans.push_back(a[i]);
        }
        return ans;
        
    }
};