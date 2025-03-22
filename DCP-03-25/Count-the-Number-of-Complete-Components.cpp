#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int completeCount = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, graph, visited, component);

                if (isComplete(component, graph)) {
                    completeCount++;
                }
            }
        }
        return completeCount;
    }

private:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited, component);
            }
        }
    }

    bool isComplete(vector<int>& component, vector<vector<int>>& graph) {
        int size = component.size();
        unordered_set<int> nodeSet(component.begin(), component.end());

        for (int node : component) {
            if (graph[node].size() != size - 1) {
                return false;
            }
            for (int neighbor : graph[node]) {
                if (nodeSet.find(neighbor) == nodeSet.end()) {
                    return false;
                }
            }
        }
        return true;
    }
};
