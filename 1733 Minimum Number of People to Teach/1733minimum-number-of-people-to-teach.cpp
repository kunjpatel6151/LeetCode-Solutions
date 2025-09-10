class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size();
        set<int> people;
        for(int i=0;i<friendships.size();i++){
            int u=friendships[i][0];
            int v=friendships[i][1];
            if(!canCommunicate(languages,u,v)){
                people.insert(u-1);
                people.insert(v-1);
            }
        }
        if(people.empty()){
            return 0;
        }
        vector<int> popular(n,0);
        for(int person:people){
            for(int language:languages[person]){
                popular[language-1]++;
            }
        }
        int M=0;
        for(int x:popular){
            M=max(x,M);
        }
        return (int)people.size()-M;
    }

    bool canCommunicate(vector<vector<int>>& languages,int u,int v){
        for(int x:languages[u-1]){
            for(int y:languages[v-1]){
                if(x==y){
                    return true;
                }
            }
        }
        return false;;
    }
};