class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zeros=0,ones=0;
        for(int x:students){
            if(x==0){
                zeros++;
            }
            else{
                ones++;
            }
        }
        for(int x:sandwiches){
            if(x==0 && zeros==0){
                return ones;
            }
            if(x==1 && ones==0){
                return zeros;
            }
            if(x==0){
                zeros--;
            }
            else{
                ones--;
            }
        }
        return 0;
    }
};