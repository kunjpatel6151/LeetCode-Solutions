class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> a;
        int i=0,j=0;
        int n=pushed.size();
        while(i<n){
            a.push(pushed[i]);
            while (!a.empty() && a.top()==popped[j]) {
                a.pop();
                j++;
            }
            i++;
        }
        if(j==n){
            return true;
        }
        else{
            return false;
        }
    }
};