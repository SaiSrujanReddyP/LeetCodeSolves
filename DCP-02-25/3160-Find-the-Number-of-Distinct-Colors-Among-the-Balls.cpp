#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor; 
        unordered_map<int, int> colorCount; 
        vector<int> result(queries.size());
        int distinctColors = 0;

        for (size_t i = 0; i < queries.size(); ++i) {
            int ball = queries[i][0], color = queries[i][1];
            if (ballColor.count(ball) && ballColor[ball] == color) {
                result[i] = distinctColors;
                continue;
            }

            if (ballColor.count(ball)) {
                int prevColor = ballColor[ball];
                colorCount[prevColor]--;
                if (colorCount[prevColor] == 0) {
                    distinctColors--;
                }
            }
            ballColor[ball] = color;
            if (colorCount[color] == 0) {
                distinctColors++;
            }
            colorCount[color]++;
            result[i] = distinctColors;
        }

        return result;
    }
};
