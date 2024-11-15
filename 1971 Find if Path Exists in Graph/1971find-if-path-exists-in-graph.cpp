#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;

        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> seen;
        stack<int> stack;
        stack.push(source);
        seen.insert(source);

        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();
            if (node == destination) return true;

            for (int neighbor : graph[node]) {
                if (seen.find(neighbor) == seen.end()) {
                    seen.insert(neighbor);
                    stack.push(neighbor);
                }
            }
        }
        return false;
    }
};