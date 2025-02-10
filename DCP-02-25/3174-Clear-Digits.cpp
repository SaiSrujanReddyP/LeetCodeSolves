#include <string>

class Solution {
public:
    std::string clearDigits(std::string s) {
        std::string result;
        for (char c : s) {
            if (isdigit(c)) {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};
