class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum=0;
        priority_queue<int> pq;
        for(int pile:piles){
            pq.push(pile);
            sum+=pile;
        }
        while(k--){
            int t=pq.top();
            pq.pop();
            int element=ceil(t/2);
            t-=element;
            pq.push(t);
            sum-=element;
        }
        return sum;
    }
};