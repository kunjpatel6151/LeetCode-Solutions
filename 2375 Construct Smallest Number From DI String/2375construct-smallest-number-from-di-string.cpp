class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size();
        vector<int> a(n+1);
        for(int i=0;i<=n;i++){
            a[i]=i+1;
        }
        int count=0;
        do{
            count=0;
            for(int i=0;i<n;i++){
                if(pattern[i]=='I' && a[i]<a[i+1]){
                    continue;
                }
                else if(pattern[i]=='D' && a[i]>a[i+1]){
                    continue;
                }
                else{
                    int temp=a[i];
                    a[i]=a[i+1];
                    a[i+1]=temp;
                    count++;
                }
            }
        }while(count!=0);
        string ans="";
        for(int i=0;i<=n;i++){
            ans+=to_string(a[i]);
        }
        return ans;
    }
};