class Solution {
public:
    int maxProduct(int n) {
        if(n/10 == 0) return -1;
        priority_queue<int> pq;
        int num=n;
        while(num>0){
            int digit=num%10;
            pq.push(digit);
            num/=10;
        }
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        return x*y;

    }
};