class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int tank,index,total;
        total=tank=index=0;
        for(int i=0;i<n;i++){
            tank+=gas[i]-cost[i];
            total+=gas[i]-cost[i];
            if(tank<0){
                index=i+1;
                tank=0;
            }
        }
        if(total>=0){
            return index;
        }
        else{
            return -1;
        }

    }
};