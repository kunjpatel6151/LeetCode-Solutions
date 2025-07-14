class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty()){
            vector<int> path=q.front();
            q.pop();
            int last=path.back();
            if(last==graph.size()-1){
                ans.push_back(path);
            }
            else{
                for(int neighbor:graph[last]){
                    vector<int> newpath=path;
                    newpath.push_back(neighbor);
                    q.push(newpath);
                }
            }
        }
        return ans;
    }
};