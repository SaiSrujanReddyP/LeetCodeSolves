#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> available(supplies.begin(), supplies.end());
        
        for (int i = 0; i < recipes.size(); i++) {
            for (const string& ingredient : ingredients[i]) {
                graph[ingredient].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        queue<string> q;
        vector<string> result;

        for (const string& supply : supplies) {
            q.push(supply);
        }

        while (!q.empty()) {
            string item = q.front();
            q.pop();

            if (indegree.find(item) != indegree.end()) {
                result.push_back(item);
            }

            for (const string& nextRecipe : graph[item]) {
                if (--indegree[nextRecipe] == 0) {
                    q.push(nextRecipe);
                }
            }
        }

        return result;
    }
};
