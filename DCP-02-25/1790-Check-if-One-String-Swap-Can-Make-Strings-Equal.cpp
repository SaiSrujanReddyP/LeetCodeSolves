class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i = -1, j = -1; 
        int count = 0;        
        for (int k = 0; k < s1.length(); k++) {
            if (s1[k] != s2[k]) {
                count++;
                if (count > 2) return false; 
                if (i == -1) i = k;
                else j = k;
            }
        }

        if (count == 0) return true;
        
        return (count == 2 && s1[i] == s2[j] && s1[j] == s2[i]);
    }
};
