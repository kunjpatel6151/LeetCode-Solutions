class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> a;
        int top=-1,s;
        for(int i=0;i<operations.size();i++){
            string c=operations[i];
            if(c=="+"){
                s=a[top]+a[top-1];
                a.push_back(s);
                top++;
            }
            else if(c=="D"){
                s=2*a[top];
                a.push_back(s);
                top++;
            }
            else if(c=="C"){
                a.pop_back();
                top--;
            }
            else{
                s=stoi(c);
                a.push_back(s); 
                top++;                               
            }
        }
        int sum=0;
        for(int i=0;i<a.size();i++){
            sum+=a[i];
        }
        return sum;
    }
};