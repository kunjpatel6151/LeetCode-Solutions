class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int N=rectangles.size();
        set<pair<int,int>> s1,s2;
        for(int i=0;i<N;i++){
            s1.insert({rectangles[i][0],rectangles[i][2]});
            s2.insert({rectangles[i][1],rectangles[i][3]});
        }
        auto it1=s1.begin();
        auto it2=s2.begin();
        int c1=0,c2=0;
        int end1=it1->second;
        int end2=it2->second;
        it1++;
        it2++;
        while(it1!=s1.end() || it2!=s2.end()){
            if(it1!=s1.end()){
                int x1=it1->first;
                int x2=it1->second;
                if(x1<end1){
                    end1=max(end1,x2);
                }
                else{
                    c1++;
                    end1=x2;
                }
                it1++;
            }
            if(it2!=s2.end()){
                int y1=it2->first;
                int y2=it2->second;
                if(y1<end2){
                    end2=max(end2,y2);
                }
                else{
                    c2++;
                    end2=y2;
                }
                it2++;
            }
            if(c1==2 || c2==2) return true;
        }
        return false;
    }
};