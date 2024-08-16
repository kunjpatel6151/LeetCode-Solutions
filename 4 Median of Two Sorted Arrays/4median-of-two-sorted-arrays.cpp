class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x=nums1.size();
        int y=nums2.size();
        std::vector<int> a(x+y);
        int i=0,j=0,k,temp;
        for(i=0;i<x;i++){
            a[i]=nums1[i];
            j++;
        }
        for(i=0;i<y;i++){
            a[j]=nums2[i];
            j++;
        }
        int n=a.size();
        for(i=0;i<n-1;i++){
            k=i;
            for(j=i+1;j<n;j++)
            {
                if(a[j]<a[k]){
                    k=j;
                }
            }
            temp=a[i];
            a[i]=a[k];
            a[k]=temp;
        }
        if(n%2==0){
            return (a[n/2]+a[(n/2)-1])/2.0;
        }
        else{
            return a[(n-1)/2];
        }
    }
};